/* $Id: sr_sysmib2.c,v 3.5.10.4 1996/07/03 20:43:46 thille Exp $
 * $Source: /release/112/cvs/Xsys/snmp/sr_sysmib2.c,v $
 *------------------------------------------------------------------
 * SNMP/SNMPv2 bi-lingual agent code.
 *
 * February 1994, Jeffrey T. Johnson
 *
 * Copyright (c) 1994-1997 by cisco Systems, Inc.
 * All rights reserved.
 *
 *------------------------------------------------------------------
 * $Log: sr_sysmib2.c,v $
 * Revision 3.5.10.4  1996/07/03  20:43:46  thille
 * CSCdi61860: Implement Jeffs glass of slim-fast for snmp
 * Branch: California_branch
 * Take hunk of common code from many mib files, make it a procedure in
 * snmp_util.c and call it from the mibs.  Save 1640 bytes.
 *
 * Revision 3.5.10.3  1996/07/01  18:46:22  hampton
 * Remove gratuitous casting.  [CSCdi61655]
 * Branch: California_branch
 *
 * Revision 3.5.10.2  1996/04/19  17:46:53  jjohnson
 * CSCdi55117:  Need to support the Draft Standard SNMPv2 SMI
 * Branch: California_branch
 * Prototypes for the <foo>_free functions are auto-generated by the
 * SR 14.0 MIB Compiler.  Make the declarations match the prototypes.
 *
 * Revision 3.5.10.1  1996/03/18  21:49:07  gstovall
 * Branch: California_branch
 * Elvis has left the building.  He headed out to California, and took the
 * port ready changes with him.
 *
 * Revision 3.4.14.3  1996/03/16  07:30:44  gstovall
 * Branch: DeadKingOnAThrone_branch
 * Make the king aware of V111_1_3.
 *
 * Revision 3.4.14.2  1996/03/07  12:34:12  mdb
 * Branch: DeadKingOnAThrone_branch
 * cisco and ANSI/POSIX libraries.
 *
 * Revision 3.4.14.1  1996/02/20  17:15:26  dstine
 * Branch: DeadKingOnAThrone_branch
 *           Sync from DeadKingOnAThrone_baseline_960122 to
 *                     DeadKingOnAThrone_baseline_960213
 *
 * Revision 3.5  1996/02/22  18:44:30  bstewart
 * CSCdi48325:  SNMP MIBs need modularized translation tables
 *
 * Revision 3.4  1995/12/14  08:27:42  jjohnson
 * CSCdi44148:  rationalize snmp library services
 *
 * Revision 3.3  1995/11/24  16:41:19  jjohnson
 * CSCdi42637:  platform-specific code should be moved out of sub_snmp
 * Install an API for accessing platform-specific SNMP objects
 *
 * Revision 3.2  1995/11/17  19:01:41  hampton
 * Remove old entries from the RCS header logs.
 *
 * Revision 3.1  1995/11/09  13:18:19  shaker
 * Bump version numbers from 2.x to 3.x.
 *
 * Revision 2.3  1995/10/07  00:33:57  jjohnson
 * CSCdi41637:  need to distinguish between 4700 models via snmp
 *
 * Revision 2.2  1995/09/22  04:36:31  enf
 * CSCdi40869:  Add frankenstorm to 11.0
 *
 * Revision 2.1  1995/06/07  22:51:06  hampton
 * Bump version numbers from 1.x to 2.x.
 *
 *------------------------------------------------------------------
 * $Endlog$
 */

/*
 *
 * Copyright (C) 1993 by SNMP Research, Incorporated.
 *
 * This software is furnished under a license and may be used and copied
 * only in accordance with the terms of such license and with the
 * inclusion of the above copyright notice. This software or any other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of the software is hereby
 * transferred.
 *
 * The information in this software is subject to change without notice
 * and should not be construed as a commitment by SNMP Research, Incorporated.
 *
 * Restricted Rights Legend:
 *  Use, duplication, or disclosure by the Government is subject to
 *  restrictions as set forth in subparagraph (c)(1)(ii) of the Rights
 *  in Technical Data and Computer Software clause at DFARS 52.227-7013
 *  and in similar clauses in the FAR and NASA FAR Supplement.
 *
 */
#include "master.h"
#include <ciscolib.h>
#include "snmp_api.h"
#include "sr_sysmib2.h"
#include "sr_sysmib2-mib.h"
#include "snmp_platform_api.h"

/* get chassis mib stuff */
#include "sr_old_lchassismib.h"

#include "../os/hostname.h"

/*
 * sysService bit definitions
 */
#define MIB_SYS_SERVICE_PHYSICAL 0x01
#define MIB_SYS_SERVICE_DATALINK 0x02
#define MIB_SYS_SERVICE_INTERNET 0x04
#define MIB_SYS_SERVICE_ENDTOEND 0x08
#define MIB_SYS_SERVICE_APPLIC   0x40

#define MAX_SYS_DESCR_LENGTH 255

char	       *snmp_contact_string;
char	       *snmp_location_string;


OctetString     sysContact;

unsigned char   _sysName[SYSSIZE];
OctetString     sysName = {_sysName, 0};

OctetString     sysLocation;

system_t        systemData =
{0, NULL, 0L, &sysContact, &sysName, &sysLocation, 0L};


void
init_sysmib2(void)
{
    OctetString	*sysDescr;
    int sysDescr_len;

    load_mib(sysmib2_OidList, sysmib2_OidListNum);
    load_oid(sysmib2_oid_table);

    snmp_contact_string = NULL;
    snmp_location_string = NULL;

    /* sysDescr is read-only, so we can set it up. */
    sysDescr_len = strlen(version);
    if (sysDescr_len > MAX_SYS_DESCR_LENGTH) {
	sysDescr = MakeOctetString(version, MAX_SYS_DESCR_LENGTH);
    } else {
	sysDescr = MakeOctetString(version, sysDescr_len);
    }
    ConvertToDisplayString(sysDescr);
    systemData.sysDescr = sysDescr;

}





/*---------------------------------------------------------------------
 * Retrieve data from the system family. This is
 * performed in 3 steps:
 *
 *   1) Test the validity of the object instance.
 *   2) Retrieve the data.
 *   3) Build the variable binding (VarBind) that will be returned.
 *---------------------------------------------------------------------*/
VarBind *
system_get(
    OID             *incoming,
    ObjectInfo      *object,
    int             searchType,
    ContextInfo     *contextInfo,
    int             serialNum)
{
    int             arg;
    void            *dp;
    system_t        *data = NULL;
    
    
    arg = snmp_scalar_instance(incoming, object, searchType);

    /*
     * Retrieve the data from the kernel-specific routine.
     */
    if ( (arg == -1) || (data = k_system_get(serialNum, contextInfo, arg)) == NULL) {
        arg = -1;
    }
    
    /*
     * Build the the variable binding for the variable that will be returned.
     */
    
    switch (arg) {
	
#ifdef I_sysDescr
    case I_sysDescr:
	dp = MakeOctetString(data->sysDescr->octet_ptr, data->sysDescr->length);
	break;
#endif /* I_sysDescr */
	
#ifdef I_sysObjectID
    case I_sysObjectID:
	dp = MakeOID(data->sysObjectID->oid_ptr, data->sysObjectID->length);
	break;
#endif /* I_sysObjectID */
	
#ifdef I_sysUpTime
    case I_sysUpTime:
	dp = &data->sysUpTime;
	break;
#endif /* I_sysUpTime */
	
#ifdef I_sysContact
    case I_sysContact:
	dp = MakeOctetString(data->sysContact->octet_ptr, data->sysContact->length);
	break;
#endif /* I_sysContact */
	
#ifdef I_sysName
    case I_sysName:
	dp = MakeOctetString(data->sysName->octet_ptr, data->sysName->length);
	break;
#endif /* I_sysName */
	
#ifdef I_sysLocation
    case I_sysLocation:
	dp = MakeOctetString(data->sysLocation->octet_ptr, data->sysLocation->length);
	break;
#endif /* I_sysLocation */
	
#ifdef I_sysServices
    case I_sysServices:
	dp = &data->sysServices;
	break;
#endif /* I_sysServices */
	
    default:
	return ((VarBind *) NULL);
	
    }      /* switch */
    
    return (MakeVarBind(object, &ZeroOid, dp));
    
}

#ifdef SETS 

/*----------------------------------------------------------------------
 * Free the system data object.
 *---------------------------------------------------------------------*/
void
system_free(system_t *data)
{
    if (data != NULL) {
	if (data->sysContact != NULL) {
	    FreeOctetString(data->sysContact);
	}
	if (data->sysName != NULL) {
	    FreeOctetString(data->sysName);
	}
	if (data->sysLocation != NULL) {
	    FreeOctetString(data->sysLocation);
	}
	free ((char *) data);
    }
}

/*----------------------------------------------------------------------
 * cleanup after system set/undo
 *---------------------------------------------------------------------*/
static int
system_cleanup(doList_t *trash)
{
    system_free(trash->data);
#ifdef SR_SNMPv2
    system_free(trash->undodata);
#endif /* SR_SNMPv2 */
    return NO_ERROR;
}

/*----------------------------------------------------------------------
 * Undo a previous set of the system family.
 *---------------------------------------------------------------------*/
#ifdef SR_SNMPv2
int
system_undo(
    doList_t       *doHead,
    doList_t       *doCur,
    ContextInfo    *contextInfo)
{
    return UNDO_FAILED_ERROR;
}
#endif SR_SNMPv2

/*---------------------------------------------------------------------
 * Determine if this SET request is valid. If so, add it to the do-list.
 * This operation is performed in 4 steps:
 *
 *   1) Validate the object instance.
 *   2) Locate a "related" do-list element, or create a new do-list
 *      element.
 *   3) Add the SET request to the selected do-list element.
 *   4) Finally, determine if the do-list element (all "related" set
 *      requests) is completely valid.
 *---------------------------------------------------------------------*/
int 
system_test(
    OID            *incoming,
    ObjectInfo     *object,
    ObjectSyntax   *value,
    doList_t       *doHead,
    doList_t       *doCur,
    ContextInfo    *contextInfo)
{
    int            instLength = incoming->length - object->oid.length;
    doList_t       *dp;
    int            found;
    
    /*
     * Validate the object instance: 1) It must be of length 1  2) and the
     * instance must be 0.
     */
    if (instLength != 1 || incoming->oid_ptr[incoming->length - 1] != 0) {
        return (NO_CREATION_ERROR); 
    }
    
    found = 0;
    
    if (!found) {
        dp = doCur;
        if ( (dp->data = malloc(sizeof(system_t))) == NULL) { 
            DPRINTF((0, "snmpd: Cannot allocate memory\n"));
            return (GEN_ERROR);
        }
        memset(dp->data, 0, sizeof(system_t));
	
        dp->setMethod = system_set;
        dp->cleanupMethod = system_cleanup;
#ifdef SR_SNMPv2
        dp->undoMethod = system_undo;
#endif /* SR_SNMPv2 */ 
        dp->state = UNKNOWN;
	
    }
    
    switch (object->nominator) {
	
#ifdef I_sysContact
    case I_sysContact:
	
        if (value->os_value->length > SYSSIZE) {
            return (WRONG_LENGTH_ERROR);
        }
	
        if (!IsDisplayString(value->os_value)) {
            return (WRONG_VALUE_ERROR);
        }

	SET_VALID(I_sysContact, ((system_t *) (dp->data))->valid);
	
	if (((system_t *) (dp->data))->sysContact != NULL) {
	    FreeOctetString(((system_t *) (dp->data))->sysContact);
	}
	
	((system_t *) (dp->data))->sysContact = 
	    MakeOctetString(value->os_value->octet_ptr, value->os_value->length);
	
	break;
#endif /* I_sysContact */
	
#ifdef I_sysName
    case I_sysName:
	
        if (value->os_value->length > SYSSIZE) {
            return (WRONG_LENGTH_ERROR);
        }
	
        if (!IsDisplayString(value->os_value)) {
            return (WRONG_VALUE_ERROR);
        }

	SET_VALID(I_sysName, ((system_t *) (dp->data))->valid);
	
	if (((system_t *) (dp->data))->sysName != NULL) {
	    FreeOctetString(((system_t *) (dp->data))->sysName);
	}
	
	((system_t *) (dp->data))->sysName = 
	    MakeOctetString(value->os_value->octet_ptr, value->os_value->length);
	
	break;
#endif /* I_sysName */
	
#ifdef I_sysLocation
    case I_sysLocation:
	
        if (value->os_value->length > SYSSIZE) {
            return (WRONG_LENGTH_ERROR);
        }
	
        if (!IsDisplayString(value->os_value)) {
            return (WRONG_VALUE_ERROR);
        }

	SET_VALID(I_sysLocation, ((system_t *) (dp->data))->valid);
	
	if (((system_t *) (dp->data))->sysLocation != NULL) {
	    FreeOctetString(((system_t *) (dp->data))->sysLocation);
	}
	
	((system_t *) (dp->data))->sysLocation = 
	    MakeOctetString(value->os_value->octet_ptr, value->os_value->length);
	
	break;
#endif /* I_sysLocation */
	
    default:
	DPRINTF((0, "snmpd: Internal error (invalid nominator in system)\n"));
	return (GEN_ERROR);
	
    }        /* switch */
    dp->state = ADD_MODIFY;
    
    return (NO_ERROR);
    
}

/*---------------------------------------------------------------------
 * Perform the kernel-specific set function for this group of
 * related objects.
 *---------------------------------------------------------------------*/
int 
system_set(
    doList_t       *doHead,
    doList_t       *doCur,
    ContextInfo    *contextInfo)
{
    return (k_system_set((system_t *) (doCur->data),
			 contextInfo, doCur->state));
}

#endif /* SETS */






system_t *
k_system_get(serialNum, contextInfo, nominator)
   int serialNum;
   ContextInfo *contextInfo;
   int nominator;
{
    char *src;
    char *dst;
    int   len;

    /* make sure sysContact and sysLocation are correct */
    sysContact.octet_ptr = snmp_contact_string;
    sysContact.length = strlen(snmp_contact_string);
    sysLocation.octet_ptr = snmp_location_string;
    sysLocation.length = strlen(snmp_location_string);

    /* build sysName from hostname and default_domain */
    dst = sysName.octet_ptr;
    len = 0;
    src = hostname;
    while (*src && len < SYSSIZE) {
	*dst++ = *src++;
        len++;
    }
    if ((src = default_domain) && len < SYSSIZE) {
	*dst++ = '.';
	len++;
	while (*src && len < SYSSIZE) {
	    *dst++ = *src++;
	    len++;
	}
    }
    sysName.length = len;

    systemData.sysUpTime = GetTimeNow();
    systemData.sysObjectID =
	snmp_platform_get_oid(SNMP_PLATFORM_OID_SYS_OBJECT_ID);
    systemData.sysServices = 0;
    /* does this bridge? */
    if (bridge_enable)
        systemData.sysServices |= MIB_SYS_SERVICE_DATALINK;
    /* does this route? */
    if (router_enable)
        systemData.sysServices |= MIB_SYS_SERVICE_INTERNET;
    /* is it a protocol convertor or does it have terminal server lines? */
    if (protocolconversion || nttylines) {
        systemData.sysServices |= MIB_SYS_SERVICE_ENDTOEND;
        systemData.sysServices |= MIB_SYS_SERVICE_APPLIC;
    }
   return(&systemData);
}

int
k_system_set(data, contextInfo, function)
   system_t *data;
   ContextInfo *contextInfo;
   int function;
{
    char *temp;
    int   len;
    static char hostdomain[256];	/* keep this static */

    if (VALID(I_sysName, data->valid)) {
	len = data->sysName->length;
	if (len != 0) {
	    bcopy(data->sysName->octet_ptr, hostdomain, len);
	    hostdomain[len] = '\0';
	    temp = (char *)strchr(hostdomain, '.');
	    if (temp != NULL)
		*temp++ = '\0';
	    else if (default_domain) {
		/* If input has no '.' at all, keep old default_domain */
		temp = hostdomain + len + 1;
		bcopy(default_domain, temp, strlen(default_domain));
		temp[strlen(default_domain)] = '\0';
	    }
	    set_hostname(hostdomain);
	    setstring(&default_domain, temp);
	}
    }

    if (VALID(I_sysContact, data->valid)) {
	len = data->sysContact->length;
	if (len == 0) {
	    temp = NULL;
	} else {
	    temp = malloc (len + 1);
	    if (temp == NULL)
		return (GEN_ERROR);
	    bcopy(data->sysContact->octet_ptr, temp, len);
	    temp[len] = '\0';
	}
        if (snmp_contact_string)
            free(snmp_contact_string);
        snmp_contact_string = temp;
    }

    if (VALID(I_sysLocation, data->valid)) {
	len = data->sysLocation->length;
	if (len == 0) {
	    temp = NULL;
	} else {
	    temp = malloc (len + 1);
	    if (temp == NULL)
		return (GEN_ERROR);
	    bcopy(data->sysLocation->octet_ptr, temp, len);
	    temp[len] = '\0';
	}
        if (snmp_location_string)
            free(snmp_location_string);
        snmp_location_string = temp;
    }
    return (NO_ERROR);
}
      
