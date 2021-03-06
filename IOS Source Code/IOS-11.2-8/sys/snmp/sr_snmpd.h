/************************************************************************
 *                                                                      *
 *                              NOTE WELL                               *
 * This is vendor-supplied and vendor-supported code.  Do not make any  *
 * modifications to this code without the knowledge and consent of the  *
 * SNMP agent group.                                                    *
 *                                                                      *
 ************************************************************************/
/* $Id: sr_snmpd.h,v 3.5.44.3 1996/07/12 23:29:07 jjohnson Exp $
 * $Source: /release/112/cvs/Xsys/snmp/sr_snmpd.h,v $
 *------------------------------------------------------------------
 * SNMP/SNMPv2 bi-lingual agent code.
 *
 * February 1994, SNMP Research
 *
 * Copyright (c) 1994-1996 by cisco Systems, Inc.
 * All rights reserved.
 *
 *------------------------------------------------------------------
 * $Log: sr_snmpd.h,v $
 * Revision 3.5.44.3  1996/07/12  23:29:07  jjohnson
 * CSCdi62131:  Need a mechanism to support logical snmp entities
 * Branch: California_branch
 *
 * Revision 3.5.44.2  1996/07/03  20:43:43  thille
 * CSCdi61860: Implement Jeffs glass of slim-fast for snmp
 * Branch: California_branch
 * Take hunk of common code from many mib files, make it a procedure in
 * snmp_util.c and call it from the mibs.  Save 1640 bytes.
 *
 * Revision 3.5.44.1  1996/03/28  16:47:02  jjohnson
 * CSCdi50399:  SNMP can drive CPU utilization to over 90%
 * Make SNMP processes default to low priority, and add a hidden config
 * command to allow customers to change it
 * Branch: California_branch
 *
 * Revision 3.5  1995/12/28  22:35:49  mordock
 * CSCdi46168:  improve snmp modularity
 * move some code and globals out of the kernel subsystem and back into
 * the snmp subsystem
 *
 * Revision 3.4  1995/11/24  16:41:16  jjohnson
 * CSCdi42637:  platform-specific code should be moved out of sub_snmp
 * Install an API for accessing platform-specific SNMP objects
 *
 * Revision 3.3  1995/11/17  19:01:16  hampton
 * Remove old entries from the RCS header logs.
 *
 * Revision 3.2  1995/11/17  00:28:29  gstovall
 * Ladies and gentlemen, I introduce to you, the port ready commit.
 *
 * Revision 3.1  1995/11/09  13:18:04  shaker
 * Bump version numbers from 2.x to 3.x.
 *
 * Revision 2.6  1995/11/08  21:26:06  shaker
 * Merge Arkansas_branch into 11.1 mainline.
 *
 * Revision 2.5  1995/09/06  20:40:21  jjohnson
 * CSCdi39761:  SNMP authentication trap locks up the SNMP task
 * Back out the hack that only addressed the snmp authentication failure
 * trap.  Replace it with a real fix that handles any trap that is being
 * generated by the process that already has exclusive access to the SNMP
 * engine.
 *
 * Revision 2.4  1995/08/22  17:18:19  jjohnson
 * CSCdi39126:  SNMP should use new primitives for mutual exclusion
 *
 * Revision 2.3  1995/07/03  22:26:27  jjohnson
 * CSCdi35401:  Parser help for snmp-server packetsize is incorrect
 * Differentiate between the minimum, maximum, and default packetsize
 *
 * Revision 2.2  1995/06/13  04:45:21  thille
 * CSCdi35746:  More control needed over tftp from SNMP
 * Add access-list checking to SNMP sets which cause tftp reads or writes
 * of config files.
 *
 * Revision 2.1  1995/06/07  22:50:43  hampton
 * Bump version numbers from 1.x to 2.x.
 *
 *------------------------------------------------------------------
 * $Endlog$
 */
/*
 *
 * Copyright (C) 1994 by SNMP Research, Incorporated.
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

/*
 *                PROPRIETARY NOTICE
 *
 * This software is an unpublished work subject to a confidentiality agreement
 * and is protected by copyright and trade secret law.  Unauthorized copying,
 * redistribution or other use of this work is prohibited.
 *
 * The above notice of copyright on this source code product does not indicate
 * any actual or intended publication of such source code.
 *
 */

/*
 * Revision History:
 *
 * snmpd.h,v
 * Revision 1.29  1995/02/06  18:11:39  battle
 * Changes for vrtx.
 *
 * Revision 1.28  1994/12/08  20:39:09  vaughn
 * Added ifndef SR_VXWORKS around memory.h
 *
 * Revision 1.27  1994/11/10  21:50:19  battle
 * fix for shared libraries
 *
 * Revision 1.26  1994/11/04  20:02:40  pearson
 * Changed -DSUBSYSTEM to allow creation of MIB instrumentation libraries, moved the system group strings to a FAR segment for Intel systems
 *
 * Revision 1.25  1994/10/28  17:32:19  vaughn
 * Placed new copyright in the file
 *
 * Revision 1.24  1994/10/26  21:58:41  vaughn
 * Changed copyrights to the new copyright structure
 *
 * Revision 1.23  1994/09/01  20:29:45  hecht
 * Added function prototypes for the routines in v1party.c. Also added a function
 * prototype for a new routine in mgmt.c (partyTAddressToUnsignedLong()).
 *
 * Revision 1.22  1994/08/29  20:59:39  battle
 * fixed typo in srcParty field
 *
 * Revision 1.21  1994/08/29  20:32:19  battle
 * modified contextInfo
 *
 * Revision 1.20  1994/08/25  15:49:47  reid
 * added i_GetVar
 *
 * Revision 1.19  1994/08/04  15:37:40  battle
 * pSOS 2.0 changes
 *
 * Revision 1.18  1994/07/28  15:33:16  reid
 * added #include <memory.h> to get prototype for memset use by the VALID macros
 *
 * Revision 1.17  1994/06/23  15:54:02  reid
 * added prototypes for OctetStringToIP, BuildReturnVarBind, and AssignValue.
 * added NEXT_ROW and CLEAR_NEXT_ROW_BIT macros.
 * the above are used by the automatically generated v_ routines.
 *
 * Revision 1.17  1994/06/21  21:24:16  reid
 * added prototypes for OctetStringToIP, BuildReturnVarBind, and AssignValue.
 * added NEXT_ROW and CLEAR_NEXT_ROW_BIT macros.
 * the above are used by the automatically generated v_ routines.
 *
 * Revision 1.16  1994/06/13  17:26:34  hecht
 * Added function prototype for snmpv1_access_check(), which is in trap.c
 *
 * Revision 1.15  1994/06/13  14:58:22  battle
 * Added async library, GetObject, and byteswapping code.
 *
 * Revision 1.14  1994/03/04  16:50:05  battle
 * Fixed problems with CISCO ifdefs.
 *
 * Revision 1.13  1994/03/03  18:21:54  levi
 * Changed some #if defined statements to #ifdef's to make mkdepend work.
 *
 * Revision 1.12  1994/02/22  15:59:56  battle
 * Corrected type define() -> defined().
 *
 * Revision 1.11  1994/02/14  16:42:21  pearson
 * Updated copyright notices for 1994.
 *
 * AMP
 *
 * Revision 1.10  1994/02/09  20:46:21  hecht
 * Changed the calling interfaces of do_trap(), SendTrap_party(),
 * send_snmpv2_trap(), and snmpv2_access_check by adding a new parameter,
 * entV2Trap, to the end of the parameter list.
 *
 * Revision 1.9  1994/02/08  00:10:09  pearson
 * Here's a brief description of the changes in this commit of the source
 * tree:
 * 	The structure of the packaged tree has changed somewhat.
 * 	Assembly language files and system-specific startup code are in
 * 	the pkg/lib/sys directory.  There is a 'serial' directory which
 * 	contains rs232 code for all of the different platforms.
 *
 * 	Uart code has a more uniform initialization call now.  For
 * 	example, init_uart() is mapped to init code for different uarts
 * 	on different systems.
 *
 * 	The national semiconductor "rib" code is in this release, along
 * 	with support for the debug/rt debugger and paradigm locate.
 * 	That created some new directories in the pkg/cmd tree.  There is
 * 	support now for a sonic driver, the ethernet repeater mib, and
 * 	sonic/ric statistics.
 *
 * 	The dos agent and utilities now configure themselves from an
 * 	ascii text file, rather than a "device driver".
 *
 * 	Various parts of the standard agent have had large stack
 * 	variables moved to malloc-ed structures to save room.
 *
 * 	Some bugs which were exposed by the marshall/levi test tool have
 * 	been fixed.
 *
 * 	Two new hello programs have been created.  Hello3 is essentially
 * 	a ping server, which allows embedded developers to test their
 * 	network stack, and hello4 allows tests of bootp and tftp.
 *
 * 	Some new routines have been added to the pkg/lib/c directory.
 * 	Dmemdump dumps memory in hex and in ascii.  32-bit versions of
 * 	memcpy, memset, etc have been created.
 *
 * Revision 1.8  1994/02/04  19:51:02  hecht
 * Added the parameter, outLen, to the function prototypes for do_snmpv1(),
 * do_snmpv2(), and findContextInfo().
 *
 * Revision 1.7  1994/01/26  18:02:14  key
 * Added postdefs.h at bottom of snmpd.h for use with Liebert UPS MIB.
 *
 * Revision 1.6  1994/01/25  19:53:06  reid
 * changed proto.h to sr_proto.h
 *
 * Revision 1.5  1994/01/13  16:13:01  battle
 * Dynix changes and tester bug fixes.
 *
 * Revision 1.4  1994/01/06  15:08:47  levi
 * Bug fixes for SCO agent.
 *
 * Revision 1.3  1993/12/23  18:38:42  battle
 * Added cvs headers to all .c and .h files.
 *
 *
 *  31-Mar-92 MRD
 *      Major re-write.
 *
 * 9-Feb-1993 DLB
 *   Removed define of MAXCOMMLEN.
 *   Removed N_TCPSTAT and friends.  These are, and have been for some time,
 *   defined in k_os.c without the N_ prefix.
 *
 * 8-Apr-1993 MGH
 *   Added the PROXY_ELEMENT structure and the declarations of the global
 *   pointers, proxy_head_ptr and proxy_tail_ptr.
 *
 *  10-May-93 MGH
 *  Changed all references to EXPORT to match the new compliance levels in
 *  RFC 1447.
 *
 *  18-May-93 MGH
 *  Changed #include <diag.h> to #include "diag.h"
 *  Changed #include <snmp.h> to #include "snmp.h"
 *  Changed #include <snmpuser.h> to #include "snmpuser.h"
 *
 * 10-Jun-1993 DLB
 *   Changed all short parameters to int.  Short parameters are a bad idea
 *   for numerous reasons I won't go into here.
 *
 * 25-June-1993 MGH
 * Added the ContextInfo structure, which will be used instead of asod in
 * the agent. Changed the name of the COMMUNITIES structure to COMMUNITY, and
 * the name of the TRAP_COMMUNITIES structure to TRAP_COMMUNITY.
 *
 * 20-July-1993 DAR
 * removed valid bitfield and modified SET_ALL_VALID and ZERO_VALID to work
 * with variable size bitfields which are now defined in snmptype.h
 *
 * 21-Jul-1993 DLB
 * Added prototype for readOnly_test (had been in snmptype.h).
 *
 * 27-July-1993 MGH
 * Added six new fields to the PROXY_ELEMENT structure: authPrivate,
 * privPrivate, authType, privType, src_timestamp, and dst_timestamp.
 *
 * 9-August-1993 MGH
 * Changed the function prototypes to the same style used in the .h files
 * in the include directory.
 *
 * 17-Sept-1993 MGH
 * Added a #include "proto.h"
 *
 * 20-Sep-1993 DLB
 * Removed the following #define's:
 * #define DEFAULT_SNMP_PORT_NUMBER	161
 * #define DEFAULT_SNMP_TRAP_PORT_NUMBER	162
 * Please use GetSNMPPort() and GetSNMPTrapPort().
 */

#ifndef _SNMPD_H_
#define _SNMPD_H_


#include "sr_snmp.h"

#ifdef SR_SNMPv2
#include "sr_secure.h"
#endif				/* SR_SNMPv2 */

#include "sr_snmpuser.h"
#include "sr_diag.h"
#include "sr_proto.h"

#include "sr_sitedefs.h"


#define NUM_TRAP_COMMUNITIES    25
#define NUM_COMMUNITIES 	25


/* search type (i.e., get or get-next) */
#define NEXT       		GET_NEXT_REQUEST_TYPE
#define EXACT      		GET_REQUEST_TYPE

/* Already defined in secure.h if SNMPv2 defined */
#ifndef SR_SNMPv2
#define SR_READ_ONLY              0x20
#define SR_READ_WRITE             0x21
#endif /* SR_SNMPv2 */

#define	SR_READ_CREATE            0x22

/* UNKNOWN is also defined in master.h, so undef it here */
#if defined(UNKNOWN)
#undef UNKNOWN
#endif

/*
 * Definitions for SET actions.
 *     1) Set function values.
 *     2) Do list definition.
 *     3) Valid bit-field macros.
 */
#define	UNUSED		    0
#define UNKNOWN		    1
#define	DELETE	    	    2
#define	ADD_MODIFY	    3
#define CREATE_AND_GO_STATE 4
#define NOT_READY_STATE     5
#define NOT_IN_SERVICE_STATE 6
#define CLOCK_SET_BACKWARDS_STATE 7

typedef struct _COMMUNITY {
    int             privs;
    char            community_name[MAXCOMMLEN];
    unsigned long   ip_address;	/* In Network Byte Order */
    int             id;
}               COMMUNITY;

typedef struct _TRAP_COMMUNITY {
    char            community_name[MAXCOMMLEN];
    unsigned long   ip_address;	/* In Network Byte Order */
}               TRAP_COMMUNITY;

#ifndef SR_SNMPv2
extern int      num_trap_communities;
#endif				/* SR_SNMPv2 */

/* New structure which replaces asod. */

#define CI_LOCAL           1
#define CI_PROXY           2
#define CI_COMMUNITY       3
#define CI_PARTY_COMMUNITY 4
#define CI_BY_DOT_ID       5

struct _ContextInfo {
    int             CIType;	/* one of the CI_ values */
    union {

#ifdef SR_SNMPv2
	struct {
	    int             Time;
	    OctetString    *Entity;
	    OID *dstParty, *srcParty, *context;
	}               local;	/* when CIType == CI_LOCAL */
	char *contextDotIdentity;  /* when CIType == CI_BY_DOT_ID */ 
#endif				/* SR_SNMPv2 */

#ifdef SR_SNMPv1

#ifndef SR_SNMPv2
	COMMUNITY      *Community;	/* when CIType == CI_COMMUNITY */
#else				/* SR_SNMPv2 */
	PARTY          *PartyCommunity;	/* when CIType == CI_PARTY_COMMUNITY */
#endif				/* SR_SNMPv2 */

#endif				/* SR_SNMPv1 */
    }               u;
};

struct _do_list {
    /* The set/abort method             */
    int             (*setMethod) SR_PROTOTYPE((doList_t *doHead,
					       doList_t *doCur,
					       ContextInfo *contextInfo));
    /* The cleanup method               */
    int             (*cleanupMethod) SR_PROTOTYPE((doList_t *trash));

#ifdef SR_SNMPv2
    /* The undo method                  */
    int             (*undoMethod) SR_PROTOTYPE((doList_t *doHead,
						doList_t *doCur,
						ContextInfo *contextInfo));
#endif				/* SR_SNMPv2 */
    int             vbPos;	/* First varBind postion            */
    int             state;	/* UNUSED/UNKNOWN/ADD_MODIFY/DELETE */
    void           *data;	/* opaque data, used by setMethod() */

#ifdef SR_SNMPv2
    void           *undodata;	/* opaque data, used by undoMethod() */
#endif				/* SR_SNMPv2 */
    struct _do_list *next;	/* next doList item                 */
};

#define ZERO_VALID(vf)		memset(vf, 0, sizeof(vf))
#define SET_VALID(n, vf)	vf[n/8] |= (1 << (n % 8))
#define SET_ALL_VALID(vf)       memset(vf, 0xff, sizeof(vf))
#define CLR_VALID(n, vf)	vf[n/8] &= ~( 1 << (n % 8))
#define VALID(n,vf)		(vf[n/8] & (1 << (n % 8)))

/* These macros are used for caching in the v_ routines to indicate if there
 * might be a hole in a table causing the cache to be invalid. The last bit
 * in the valid bitfield defined in the snmptype.h file is reserved for this
 * purpose.
 */
#define NEXT_ROW(vf)           (vf[sizeof(vf) - 1] & (1 << 7))
#define CLEAR_NEXT_ROW_BIT(vf) \
        vf[(sizeof(vf) * 8 - 1) / 8] &= ~(1 << ((sizeof(vf) * 8 - 1) % 8))

/* mgmt.c */
struct _ContextInfo *findContextInfo SR_PROTOTYPE((unsigned long from_addr, 
  struct _AuthHeader *auth_ptr, short *limit, int *error_code,
  unsigned int outLen));
struct _Pdu *make_error_pdu SR_PROTOTYPE((int type, long req_id, int status, 
  int counter, struct _Pdu *in_pdu_ptr, int domain));	/* in mgmt.c */
unsigned long partyTAddressToUnsignedLong SR_PROTOTYPE((int index));

#define GetTimeNow snmp_sysUpTime

#ifdef SR_SNMPv1

#ifndef SR_SNMPv2
/* No access control or exceptions in v1 only */
#define CheckMIBView(oid,view)             1
#define CheckClassMIBView(oid,view)       1
#define GetViewIndex(context)              0
#define exception(type, name, version)       NULL
#endif				/* SR_SNMPv2 */

#endif				/* SR_SNMPv1 */

extern void     initialize SR_PROTOTYPE((void));	/* in initial.c    */

unsigned short do_mgmt SR_PROTOTYPE((unsigned char *inPdu, unsigned int inLen,
  unsigned long srcIpAddr, unsigned int srcUdpPort, unsigned long dstIpAddr,
  unsigned int dstUdpPort, unsigned char *outPkt, unsigned int outLen));

#ifdef SR_SNMPv1
unsigned short build_snmpv1_response SR_PROTOTYPE((struct _AuthHeader *in_auth_ptr,
  struct _Pdu *out_pdu_ptr, unsigned char *outPkt));
#endif				/* SR_SNMPv1 */

#ifdef SR_SNMPv2
unsigned short build_snmpv2_response SR_PROTOTYPE((struct _AuthHeader *in_auth_ptr,
  struct _Pdu *out_pdu_ptr, unsigned char *outMsg));
#endif				/* SR_SNMPv2 */

#ifdef	SR_SNMPv1

struct _Pdu *do_snmpv1 SR_PROTOTYPE((unsigned char *inPdu, unsigned int inLen, 
  unsigned long srcIpAddr, unsigned int srcUdpPort,
  struct _AuthHeader *in_auth_ptr, unsigned int outLen));
#endif				/* SR_SNMPv1 */

#ifdef	SR_SNMPv2

struct _Pdu  *do_snmpv2 SR_PROTOTYPE((unsigned char *inPdu, unsigned int inLen,
  unsigned long srcIpAddr, unsigned int srcUdpPort, unsigned long dstIpAddr,
  unsigned int dstUdpPort, struct _AuthHeader *in_auth_ptr, 
  unsigned int outLen));

#endif				/* SR_SNMPv2 */

struct _Pdu  *do_response SR_PROTOTYPE((struct _Pdu *inpdu, 
  struct _ContextInfo *contextInfo, int limit, struct _OID *context, 
  int version));

/* v_party.c */

#ifdef SR_SNMPv2
int set_row_status SR_PROTOTYPE((int value, int exists, int *state, long *status));
int party_create_check SR_PROTOTYPE((struct _OID *AuthProtocol,
  struct _OctetString *AuthPrivate, struct _OID *PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid));
int party_status_check SR_PROTOTYPE((struct _OID *AuthProtocol,
  struct _OctetString *AuthPrivate, struct _OID *PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid));
int party_service_check SR_PROTOTYPE((struct _OID *AuthProtocol,
  struct _OctetString *AuthPrivate, struct _OID *PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid));
int not_ready_check SR_PROTOTYPE((struct _OID *AuthProtocol,
  struct _OctetString *AuthPrivate, struct _OID *PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid));
int party_not_ready_check SR_PROTOTYPE((long AuthProtocol,
  struct _OctetString *AuthPrivate, long PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid));
int not_in_service_check SR_PROTOTYPE((long AuthProtocol,
  struct _OctetString *AuthPrivate, long PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid, int state, int index));
int party_active_check SR_PROTOTYPE((long AuthProtocol,
  struct _OctetString *AuthPrivate, long PrivProtocol,
  struct _OctetString *PrivPrivate, struct _OID *party_clone,
  char *valid, int state, int index));
#endif				/* SR_SNMPv2 */

/* traputil.c */
void snmp_trap SR_PROTOTYPE((long genTrap,
			     long specTrap,
			     OID **varBindList,
			     OID *enterprise,
			     char *entV2Trap));

void snmp_link_trap SR_PROTOTYPE((long genTrap,
				  hwidbtype *idb));

void snmp_coldstart_trap SR_PROTOTYPE((void));

void snmp_authentication_trap SR_PROTOTYPE((int protocol,
					    addrtype *source_address));

void register_snmp_trap (ulong keyword, const char *oid_str);

/* trap.c */
void do_trap SR_PROTOTYPE((long genTrap, long specTrap, struct _VarBind *vb, struct _OID *enterprise, char *entV2Trap));

void SendTrap_comm SR_PROTOTYPE((struct _TRAP_COMMUNITY *trap_community, struct _OID *enterprise, long genTrap, long specTrap, struct _VarBind *vb, struct _OctetString *localAddr, int ToSoc));

void SendTrap_party SR_PROTOTYPE((int pos, struct _OID *enterprise, long genTrap, long specTrap, struct _VarBind *vb, struct _OctetString localAddr, int ToSoc, char *entV2Trap));

void send_snmpv2_trap SR_PROTOTYPE((long genTrap, struct _VarBind *vb, int ToSoc, int src_pos, int dst_pos, int context_pos, long dstAddr, char *entV2Trap));

void send_comm_v2_trap SR_PROTOTYPE((struct _OID *enterprise, long genTrap, long specTrap, struct _VarBind *vb, struct _OctetString localAddr, int ToSoc, int src_pos, int dst_pos, int context_pos, long dstAddr));

int access_check SR_PROTOTYPE((int pos, int *src_pos, int *dst_pos, int *context_pos));

int snmpv2_access_check SR_PROTOTYPE((int src_pos, int context_pos, long genTrap, struct _VarBind *vb, char *entV2Trap));

int snmpv1_access_check SR_PROTOTYPE((int src_pos, int context_pos, struct _VarBind *vb, struct _OID *enterprise));

/* core.c (extracted from original objectdb.c) */

extern ObjectInfo    **OidIndex;
extern long            NumObjects;

void snmp_core_init (void);

/* snmp_chain.c */
void snmp_parser_init(void);

/* snmp_parser.c */
void snmp_parse_config_init(void);

/* snmp_setup.c */
void snmp_setup_common(setup_struct *sp);

/* snmp_resource.c */

void snmp_resource_init(void);
void register_snmp_resource (const OID *resource_oid, const char *resource_descr);

/* objectdb.c */

void load_mib (const ObjectInfo *mib, const uint num);
int find_object SR_PROTOTYPE((struct _OID *oid, int searchType));
int NextObjectClass SR_PROTOTYPE((int i, int domain));
int FindObjectClass SR_PROTOTYPE((struct _OID *oid, int searchType, int domain));
struct _VarBind *GetExactObjectInstance SR_PROTOTYPE((struct _OID *incoming, long view, struct _ContextInfo *contextInfo, int serialNum, int domain));

struct _VarBind *GetNextObjectInstance SR_PROTOTYPE((struct _OID *incoming, long view, struct _ContextInfo *contextInfo, int serialNum, int domain));

#ifdef SR_SNMPv2
struct _VarBind *exception SR_PROTOTYPE((int type, struct _OID *name, int domain));
#endif /* SR_SNMPv2 */
struct _ObjectInfo *GetOidElem SR_PROTOTYPE((int i));
VarBind *i_GetVar SR_PROTOTYPE((struct _ContextInfo *contextInfo, int searchType, OID *var));

/* sets.c */
struct _Pdu *do_sets SR_PROTOTYPE((struct _Pdu *inPdu, struct _ContextInfo *contextInfo, struct _OID *context, int domain));

/* inst_lib.c */
extern  int InstToInt SR_PROTOTYPE((struct _OID *inst, int index, long *val, int searchType, int *carry));
extern  int InstToUInt SR_PROTOTYPE((struct _OID *inst, int index, unsigned long *val, int searchType, int *carry));
extern  int InstToIP SR_PROTOTYPE((struct _OID *inst, int index, unsigned long *ipAddr, int searchType, int *carry));
extern  int InstToFixedOctetString SR_PROTOTYPE((struct _OID *inst, int index, struct _OctetString **os, int searchType, int *carry, int size));
extern  int InstToImpliedOctetString SR_PROTOTYPE((struct _OID *inst, int index, struct _OctetString **os, int searchType, int *carry));
extern  int InstToVariableOctetString SR_PROTOTYPE((struct _OID *inst, int index, struct _OctetString **os, int searchType, int *carry));
extern  int InstToImpliedOID SR_PROTOTYPE((struct _OID *inst, int index, struct _OID **os, int searchType, int *carry));
extern  int InstToVariableOID SR_PROTOTYPE((struct _OID *inst, int index, struct _OID **os, int searchType, int *carry));
extern  int GetVariableIndexLength SR_PROTOTYPE((struct _OID *inst, int index));
extern  int GetImpliedIndexLength SR_PROTOTYPE((struct _OID *inst, int index));
extern  int CmpOIDInst SR_PROTOTYPE((struct _OID *ptr1, struct _OID *ptr2, int index));
extern OctetString *IPToOctetString SR_PROTOTYPE((unsigned long IPAddr));
extern unsigned long OctetStringToIP SR_PROTOTYPE((OctetString *os));
extern VarBind *BuildReturnVarBind SR_PROTOTYPE((int nominator, void *data, ObjectInfo *object, OID *inst));
extern int AssignValue SR_PROTOTYPE((ObjectInfo *object, void *dp, ObjectSyntax *value));

#include "snmp_util.h"

int k_initialize SR_PROTOTYPE((void));
int k_terminate SR_PROTOTYPE((void));

/*
 * Types of traps known to do_trap().
 */
#define COLD_START_TRAP		0L
#define WARM_START_TRAP		1L
#define LINK_DOWN_TRAP		2L
#define LINK_UP_TRAP		3L
#define AUTHEN_FAILURE_TRAP	4L
#define EGP_NEIGHBOR_LOSS_TRAP	5L
#define ENTERPRISE_TRAP		6L




typedef unsigned long Ounit;
typedef unsigned long bit_32;

struct object_index {
    struct object_info *object;
    bit_32          permbits;
};

#ifdef SR_SNMPv2


#endif				/* SR_SNMPv2 */

#ifdef SR_SNMPv2
#ifdef SR_SNMPv1
/* In v1party.c */
int InitV1Parties SR_PROTOTYPE((void));
unsigned long FindMaxPartyInstance SR_PROTOTYPE((void));
int FindV1Party SR_PROTOTYPE((char *community_string));
long AddV1Party SR_PROTOTYPE((char *community, unsigned long ipAddr, unsigned long instance, int privs, int party_index));
int AddAclEntry SR_PROTOTYPE((long sindex, long tindex, int privs, int rindex, int pos));
int FindNumCommunities SR_PROTOTYPE((void));
char *GetInetNtoa SR_PROTOTYPE((unsigned long addr));

/* used by v1party.c */
void GetAgentIPAddress SR_PROTOTYPE((char *resultString));
#endif /* SR_SNMPv1 */
#endif /* SR_SNMPv2 */

int readOnly_test SR_PROTOTYPE((struct _OID *incoming, struct _ObjectInfo *object, struct _ObjectSyntax *value, struct _do_list *doHead, struct _do_list *doCur, struct _ContextInfo *auth));

#ifdef NOT_FOR_CISCO
/*
 * Code generated by the mib compiler and any macros/defintions that
 * depend on output from the mib compiler.
 */

#if ! ( defined(SUBSYSTEM) )
#include "snmptype.h"
#include "snmpsupp.h"
#include "snmpdefs.h"
#include "snmppart.h"
#endif	/* ! ( defined(SUBSYSTEM) ) */


#ifdef SUBSYSTEM
#include "mibout.h"
#endif /* SUBSYSTEM */
#endif /* NOT_FOR_CISCO */

/* VXWORKS uses SR_OFFSET as well, but not in any code we'd touch so I'm 
    replacing it with ours */

#define SR_OFFSET(x,off)	(void *)((char *)x + (off * sizeof(long)))

#define U_OFFSET(x,off)	(void *)((char *)x + (off * sizeof(unsigned long)))


/*============================================================
 * Global data initialization section.
 *============================================================*/

    extern int      LogLevel;
    extern OID      ZeroOid;
    extern long     StartTime;

extern OID	nullOID;
extern const OID ciscoOID;
extern process_priority_t snmp_priority;
extern boolean	snmp_serving;
extern int	snmp_size;
extern ulong	snmp_def_timeout;
extern int      snmp_tftp_server_acl;
extern int	snmp_def_qlen;
extern boolean	snmp_shutdown;
extern ipaddrtype snmp_bad_addr;
extern idbtype *snmp_trap_idb;
extern watched_semaphore *snmp_semaphore;
extern pid_t    snmp_semaphore_pid;
extern boolean	snmp_nosparse;    /* disable sparse tables in ifmib */

/*
 * structure for maintaining trap types
 */
#define traptype struct traptype_
traptype {
    traptype *next;			/* ptr to next entry */
    char *trap_oid_str;			/* string representation of trap_oid */
    ulong trap_keyword_id;		/* trap's associated keyword id */
};

extern queuetype  trap_registrationQ;	/* Q elements are of type traptype */

/*
 * structure for maintaining object resources
 */
#define ortype struct ortype_
ortype {
    ortype *next;			/* ptr to next entry */
    int or_idx;				/* resource index */
    OID *or_oid;			/* resource OID */
    char *or_descr;			/* resource description */
};

extern queuetype  object_resourcesQ;	/* Q elements are of type ortype */

#define SNMP_DEF_QLEN           10
#define SNMP_DEF_TIMEOUT        (30*ONESEC)

#ifdef  MAIN
#define EXTDECL
#else				/* MAIN */
#define EXTDECL extern
#endif				/* MAIN */


#ifdef SR_SNMPv2
    EXTDECL unsigned long basetime;
#endif				/* SR_SNMPv2 */

    EXTDECL COMMUNITY *communities;
    EXTDECL int     num_communities;

    EXTDECL TRAP_COMMUNITY *trap_communities;
    EXTDECL int     num_trap_communities;

#define SYSSIZE		255
/*
 * limits for snmp packet sizes
 * SNMP_MAX_MSG_SIZE_MIN is the largest packetsize we must support
 * SNMP_MAX_MSG_SIZE_DEF is the default packetsize we will use
 * SNMP_MAX_MSG_SIZE_MAX is the largest packetsize we can support
 */
#define SNMP_MAX_MSG_SIZE_MIN	484
#define SNMP_MAX_MSG_SIZE_DEF	1500
#define SNMP_MAX_MSG_SIZE_MAX	MAXDATAGRAMSIZE - ENCAPBYTES

/*
 * the following is equal to SNMP_MAX_MSG_SIZE_MAX unless the size of
 * hugh buffers has been reconfigured.  It is only defined for use
 * by the parser
 */
#define SNMP_MAX_MSG_SIZE_MAX_CONST	DEF_HUGEDATA - ENCAPBYTES

#define SNMP_PRIORITY_DEF	PRIO_LOW

#define SUBSYSTEM
#define INAPPROPRIATE_STUFF
#if defined(SUBSYSTEM)
#undef INAPPROPRIATE_STUFF
#endif	/* defined(SUBSYSTEM) */


#ifdef INAPPROPRIATE_STUFF
/*
 * The system group.
 */
#define SYSSIZE		255

#ifndef MAIN
    extern OctetString sysDescr;
    extern OctetString sysContact;
    extern OctetString sysName;
    extern OctetString sysLocation;
    extern OID      sysOID;

    extern system_t systemData;
#else				/* MAIN */
    unsigned char   FAR _sysDescr[SYSSIZE + 1];	/* don't null terminate */
    OctetString     sysDescr = {_sysDescr, 0};

    unsigned char   FAR _sysContact[SYSSIZE + 1]; /* don't null terminate */
    OctetString     sysContact = {_sysContact, 0};

    unsigned char   FAR _sysName[SYSSIZE + 1];	/* don't null terminate */
    OctetString     sysName = {_sysName, 0};

    unsigned char   FAR _sysLocation[SYSSIZE + 1]; /* don't null terminate */
    OctetString     sysLocation = {_sysLocation, 0};

    unsigned long   _sysOID[2];	/* 0.0 *//* %%% Put in MIB comiler OID */
    OID             sysOID = {2L, _sysOID};

    system_t        systemData =
    {&sysDescr, &sysOID, 0L, &sysContact, &sysName, &sysLocation, 72};

#endif				/* MAIN */


/*
 * The snmp group.
 */
    EXTDECL snmp_t  snmpData;

/*
 * The snmpv2 group.
 */

#ifdef SR_SNMPv2
#define SNMPv2_TRAPS_ENABLED 1
#define SNMPv2_TRAPS_DISABLED 2


    EXTDECL snmpStats_t snmpStatsData;

    EXTDECL snmpV1_t snmpV1Data;

    EXTDECL snmpTrap_t snmpTrapData;

    EXTDECL snmpOR_t snmpORData;

    EXTDECL snmpOREntry_t snmpOREntryData;

    EXTDECL snmpSet_t snmpSetData;
#endif				/* SR_SNMPv2 */


#endif				/* INAPPROPRIATE_STUFF */

#ifdef USE_POSTDEFS
#include "postdefs.h"
#endif /* USE_POSTDEFS */

#endif				/* _SNMPD_H_ */
