
atmsig_ie.h,15948
#define __ATMSIG_IE_H__ 90,3211
#define V31 94,3250
typedef struct atmSig_ieHeader_ atmSig_ieHeader_101,3354
} atmSig_ieHeader;atmSig_ieHeader105,3567
#define ATMSIG_IEHDRSIZE 107,3587
#define ATMSIG_IECODING_ITU 109,3617
#define ATMSIG_IECODING_NET 110,3675
#define ATMSIG_IECODING_MASK 111,3751
#define ATM_AAL_IE 118,3981
#define ATM_USERCELLRATE_IE 119,4034
#define ATM_BROADBAND_BEARERCAP_IE 120,4087
#define ATM_BROADBAND_HIGHLAYER_IE 121,4140
#define ATM_BROADBAND_LOWLAYER_IE 122,4193
#define ATM_CALLSTATE_IE 123,4246
#define ATM_CALLEDPARTY_NUMBER_IE 124,4299
#define ATM_CALLEDPARTY_SUBADDR_IE 125,4352
#define ATM_CALLINGPARTY_NUMBER_IE 126,4405
#define ATM_CALLINGPARTY_SUBADDR_IE 127,4458
#define ATM_CAUSE_IE 128,4511
#define ATM_CONNECTIONIDENTIFIER_IE 129,4564
#define ATM_QOS_IE 130,4617
#define ATM_RESTARTINDICATOR_IE 131,4670
#define ATM_BROADBAND_SENDINGCMPLT_IE 132,4723
#define ATM_TRANSIT_NTWRKSEL_IE 133,4776
#define ATM_ENDPOINT_REFERENCE_IE 134,4829
#define ATM_ENDPOINT_STATE_IE 135,4882
#define ATM_BROADBAND_LCKNGSHFT_IE 136,4935
#define ATM_BROADBAND_NON_LCKNGSHFT_IE 137,4988
#define ATM_BBAND_REPEATINDICATOR_IE 138,5041
#define ATM_RCV_AAL 141,5096
#define ATM_RCV_USERCELLRATE 142,5147
#define ATM_RCV_BROADBAND_BEARERCAP 143,5198
#define ATM_RCV_BROADBAND_HIGHLAYER 144,5249
#define ATM_RCV_BROADBAND_LOWLAYER 145,5300
#define ATM_RCV_CALLSTATE 146,5351
#define ATM_RCV_CALLEDPARTY_NUMBER 147,5402
#define ATM_RCV_CALLEDPARTY_SUBADDR 148,5453
#define ATM_RCV_CALLINGPARTY_NUMBER 149,5504
#define ATM_RCV_CALLINGPARTY_SUBADDR 150,5555
#define ATM_RCV_CAUSE 151,5606
#define ATM_RCV_CONNECTIONIDENTIFIER 152,5657
#define ATM_RCV_QOS 153,5708
#define ATM_RCV_RESTARTINDICATOR 154,5759
#define ATM_RCV_BROADBAND_SENDINGCMPLT 155,5810
#define ATM_RCV_TRANSIT_NTWRKSEL 156,5861
#define ATM_RCV_ENDPOINT_REFERENCE 157,5912
#define ATM_RCV_ENDPOINT_STATE 158,5963
#define ATM_RCV_REPEATINDICATOR_IE 159,6014
#define ATM_RCV_INVALID_IE 160,6064
#define ATM_CAUSE_MAXSIZE 166,6187
#define ATM_CALLSTATE_MAXSIZE 167,6237
#define ATM_ENDPTREF_MAXSIZE 168,6287
#define ATM_ENDPTSTATE_MAXSIZE 169,6337
#define ATM_AAL_MAXSIZE 170,6387
#define ATM_USERCELLRATE_MAXSIZE 171,6437
#define ATM_CONNECTIONID_MAXSIZE 172,6487
#define ATM_QOS_MAXSIZE 173,6537
#define ATM_BBAND_HILAYER_MAXSIZE 174,6587
#define ATM_BBAND_BEARERCAP_MAXSIZE 175,6637
#define ATM_BBAND_LOLAYER_MAXSIZE 176,6687
#define ATM_BBAND_LOCKSHFT_MAXSIZE 177,6737
#define ATM_BBAND_NONLOCKSHFT_MAXSIZE 178,6787
#define ATM_SENDCMPLT_MAXSIZE 179,6837
#define ATM_BBAND_REPEATIND_MAXSIZE 180,6887
#define ATM_CALLINGPARTY_MAXSIZE 181,6937
#define ATM_CALLINGPARTY_SUBADDR_MAXSIZE 182,6987
#define ATM_CALLEDPARTY_MAXSIZE 183,7037
#define ATM_CALLEDPARTY_SUBADDR_MAXSIZE 184,7087
#define ATM_TRANSIT_NTWRKSEL_MAXSIZE 185,7137
#define ATM_RESTART_IND_MAXSIZE 186,7187
#define ATM_REPEAT_IND_MAXSIZE 187,7237
#define ATM_AALIE_TYPE1 196,7420
#define ATM_AALIE_TYPE34 197,7477
#define ATM_AALIE_TYPE5 198,7536
#define ATM_AALIE_TYPEX 199,7593
#define ATM_AALIE_TYPEINVLD 200,7665
#define ATM_AALIE_CPI 203,7762
#define ATM_AALIE_MODE_MASK 206,7823
#define ATM_AALIE_MODE_MSG 207,7865
#define ATM_AALIE_MODE_STREAM 208,7907
#define ATM_AALIE_MODE_INVALID 209,7949
#define ATM_AALIE_SDU1_MASK 212,8009
#define ATM_AALIE_SDU2_MASK 213,8051
#define ATM_AALIE_SDU3_MASK 214,8093
#define ATM_AALIE_MID1_MASK 217,8156
#define ATM_AALIE_MID2_MASK 218,8198
#define ATM_AALIE_SSPI 221,8284
#define ATM_AALIE_SUBTYPE_ID 224,8345
#define ATM_AALIE_SUBTYPE_NULL 225,8390
#define ATM_AALIE_SUBTYPE_VOICE 226,8433
#define ATM_AALIE_SUBTYPE_SYNC 227,8513
#define ATM_AALIE_SUBTYPE_ASYNC 228,8589
#define ATM_AALIE_SUBTYPE_AUDIO 229,8666
#define ATM_AALIE_SUBTYPE_VIDEO 230,8736
#define ATM_AALIE_CBR_IDENT 234,8810
#define ATM_AALIE_CBR_64 235,8852
#define ATM_AALIE_CBR_1544 236,8912
#define ATM_AALIE_CBR_6312 237,8974
#define ATM_AALIE_CBR_32064 238,9036
#define ATM_AALIE_CBR_44736 239,9099
#define ATM_AALIE_CBR_97728 240,9162
#define ATM_AALIE_CBR_2048 241,9225
#define ATM_AALIE_CBR_8448 242,9292
#define ATM_AALIE_CBR_34368 243,9359
#define ATM_AALIE_CBR_139264 244,9427
#define ATM_AALIE_CBR_N64 245,9491
#define ATM_AALIE_CBR_N8 246,9555
#define ATM_AALIE_MULTIPLIER_ID 249,9666
#define ATM_AALIE_CRT_ID 252,9739
#define ATM_AALIE_CRT_NULL 253,9781
#define ATM_AALIE_CRT_SRTS 254,9865
#define ATM_AALIE_CRT_ACR 255,9940
#define ATM_AALIE_ECT_ID 258,10047
#define ATM_AALIE_ECT_NULL 259,10089
#define ATM_AALIE_ECT_FECI 260,10131
#define ATM_AALIE_ECT_FECD 261,10213
#define ATM_AALIE_SDT_ID 264,10330
#define ATM_AALIE_SDT_NULL 265,10372
#define ATM_AALIE_SDT 266,10414
#define ATM_AALIE_PFC_ID 269,10500
typedef struct atmSig_aalType1Ie_ atmSig_aalType1Ie_274,10586
} atmSig_aalType1Ie;atmSig_aalType1Ie290,11293
typedef struct atmSig_aalType1IeV31_ atmSig_aalType1IeV31_293,11316
} atmSig_aalType1IeV31;atmSig_aalType1IeV31309,12027
#define ATM_AALIE_FWD_SDUSZ_ID 312,12053
#define ATM_AALIE_BWD_SDUSZ_ID 313,12093
#define ATM_AALIE_MID_SIZE_ID 314,12133
#define ATM_AALIE_MODE_ID 315,12173
#define ATM_AALIE_SSCSTYPE_ID 316,12213
#define ATM_AALIE_SSCS_NULL 321,12282
#define ATM_AALIE_SSCS_ADATA 322,12322
#define ATM_AALIE_SSCS_UDATA 323,12392
#define ATM_AALIE_SSCS_FRAMERELAY 324,12464
typedef struct atmSig_aalType34Ie_ atmSig_aalType34Ie_329,12577
} atmSig_aalType34Ie;atmSig_aalType34Ie341,12983
#define ATMSIG_AALTYPE34_IESIZE 344,13007
#define ATMSIG_AALTYPE5_IESIZE 350,13161
#define ATMSIG_AALTYPE5_IESIZE_V31 351,13203
typedef struct atmSig_aalType5Ie_ atmSig_aalType5Ie_353,13245
} atmSig_aalType5Ie;atmSig_aalType5Ie363,13607
typedef struct atmSig_AalTypeXIe_ atmSig_AalTypeXIe_371,13742
} atmSig_aalTypeXIe;atmSig_aalTypeXIe377,13909
typedef struct atmSig_connectionIdIe_ atmSig_connectionIdIe_383,14067
} atmSig_connectionIdIe;atmSig_connectionIdIe387,14162
#define ATMSIG_CONNECTIONID_IESIZE 389,14189
#define ATM_VPASSOC_SIG 392,14290
typedef struct atmSig_bBearerCapability_t atmSig_bBearerCapability_t398,14375
} atmSig_bBearerCapability;atmSig_bBearerCapability402,14482
#define ATMSIG_BBEARERCAP_IESIZE 404,14511
#define ATM_BCLASS_MASK 407,14568
#define ATM_BCLASS_BCOBA 408,14603
#define ATM_BCLASS_BCOBC 409,14638
#define ATM_BCLASS_BCOBX 410,14673
#define ATM_TRAFFICTYPE_MASK 413,14728
#define ATM_TRAFFICTYPE_NULL 414,14768
#define ATM_TRAFFICTYPE_CBR 415,14808
#define ATM_TRAFFICTYPE_VBR 416,14848
#define ATM_TIMINGREQ_MASK 419,14915
#define ATM_TIMINGREQ_NULL 420,14955
#define ATM_TIMINGREQ_EETR 421,14995
#define ATM_TIMINGREQ_EETNR 422,15035
#define ATM_TIMINGREQ_RSRVD 423,15075
#define ATM_CLIPPING_MASK 426,15149
#define ATM_CLIPPING_NULL 427,15189
#define ATM_CLIPPING_YES 428,15229
#define ATM_UPAC_MASK 431,15308
#define ATM_UPAC_NULL 432,15348
typedef struct atmSig_callStateIe_ atmSig_callStateIe_439,15416
} atmSig_callStateIe;atmSig_callStateIe441,15469
#define ATMSIG_CALLSTATE_IESIZE 443,15492
#define ATM_CALLSTATE_NULL 446,15554
#define ATM_CALLSTATE_CALLINIT 447,15613
#define ATM_CALLSTATE_OUTCALLPROC 448,15682
#define ATM_CALLSTATE_CALLPRESENT 449,15761
#define ATM_CALLSTATE_CONNECTREQ 450,15828
#define ATM_CALLSTATE_INCALLPROC 451,15898
#define ATM_CALLSTATE_ACTIVE 452,15977
#define ATM_CALLSTATE_RELREQ 453,16038
#define ATM_CALLSTATE_RELIND 454,16108
#define ATM_CALLSTATE_REST0 455,16181
#define ATM_CALLSTATE_REST1 456,16239
#define ATM_CALLSTATE_REST2 457,16308
#define ATM_ENDPOINTSTATE_NULL	460,16407
#define ATM_ENDPOINTSTATE_ADDPRTYINIT	461,16457
#define ATM_ENDPOINTSTATE_PRTYALRTDLVD	462,16528
#define ATM_ENDPOINTSTATE_ADDPRTYRCVD	463,16605
#define ATM_ENDPOINTSTATE_PRTYALRTRCVD	464,16675
#define ATM_ENDPOINTSTATE_DRPPRTYINIT	465,16751
#define ATM_ENDPOINTSTATE_DRPPRTYRCVD 466,16823
#define ATM_ENDPOINTSTATE_ACTIVE	467,16896
#define ATM_QOSIE_ID 475,17050
#define ATM_QOSIE_UNSPECD 476,17096
#define ATM_QOSIE_CLASS1 477,17142
#define ATM_QOSIE_CLASS2 478,17188
#define ATM_QOSIE_CLASS3 479,17234
#define ATM_QOSIE_CLASS4 480,17280
#define ATM_QOSIE_RES 481,17326
typedef struct atmSig_qosIe_ atmSig_qosIe_483,17398
} atmSig_qosIe;atmSig_qosIe486,17466
#define ATMSIG_QOS_IESIZE 487,17482
#define ATMSIG_QOS_CII 488,17514
#define ATMSIG_QOS_CII_ITU 489,17549
#define ATM_BBAND_SENDCMPLTIE_ID 494,17663
#define ATM_BBAND_SENDCMPLT_IND 495,17708
#define ATM_CAUSEIE_ID 502,17775
typedef struct atmSig_causeIe_ atmSig_causeIe_504,17813
} atmSig_causeIe;atmSig_causeIe507,17886
#define ATMSIG_CAUSE_IESIZE 509,17905
#define ATM_CAUSELOC_USER 512,17956
#define ATM_CAUSELOC_PRIV_NTWRK 513,18001
#define ATM_CAUSELOC_PUBLIC_NTWRK 514,18046
#define ATM_CAUSELOC_TRANSIT_NTWRK 515,18091
#define ATM_CAUSELOC_PUBNTWRK_REMOTE 516,18136
#define ATM_CAUSELOC_PRIVNTWRK_REMOTE 517,18181
#define ATM_CAUSELOC_INTERNTL_NTWRK 518,18226
#define ATM_CAUSELOC_NTWRK_BYND 519,18271
#define ATM_CAUSE_UNALLOC 525,18387
#define ATM_CAUSE_NOROUTE_TO_NTWRK 528,18480
#define ATM_CAUSE_NOROUTE_TO_DEST 531,18559
#define ATM_CAUSE_VPCI_UNACCEPT 534,18636
#define ATM_CAUSE_CALL_CLEARING 537,18722
#define ATM_CAUSE_USER_BUSY 540,18787
#define ATM_CAUSE_NOUSER_RSP 543,18861
#define ATM_CAUSE_CALL_REJ 546,18930
#define ATM_CAUSE_NUM_CHANGED 549,19000
#define ATM_CAUSE_USER_REJ 552,19089
#define ATM_CAUSE_DEST_INACTIVE 555,19169
#define ATM_CAUSE_INVALID_NUMBER_FMT 558,19267
#define ATM_CAUSE_STATUSENQ_RSP 561,19357
#define ATM_CAUSE_NORMAL_UNSPECIFIED 564,19432
#define ATM_CAUSE_VPCI_UNAVAIL 567,19520
#define ATM_CAUSE_VPCI_FAIL 570,19612
#define ATM_CAUSE_CELLRATE_UNAVAIL 573,19719
#define ATM_CAUSE_NTWRK_OUT_OF_ORDER 576,19839
#define ATM_CAUSE_TMP_FAILURE 579,19912
#define ATM_CAUSE_ACCESS_INFO_DISCRD 582,19996
#define ATM_CAUSE_NO_VPCI 585,20073
#define ATM_CAUSE_RSRC_UNAVAIL 588,20162
#define ATM_CAUSE_QOS_UAVAIL 591,20248
#define ATM_CAUSE_USR_CELLRATE_UNAVAIL 594,20332
#define ATM_CAUSE_BEARERCAP_UNAUTH 597,20420
#define ATM_CAUSE_BEARERCAP_NOTAVAIL 600,20517
#define ATM_CAUSE_SERVICE_UNAVAIL 603,20617
#define ATM_CAUSE_BEARERCAP_UNIMP 606,20706
#define ATM_CAUSE_UNSUPPORTED 609,20807
#define ATM_CAUSE_AALPARAM_NOT_SUPPORT 612,20918
#define ATM_CAUSE_INVALID_CALLREF 615,21002
#define ATM_CAUSE_CHANNEL_NOTPRESENT 618,21091
#define ATM_CAUSE_INCOMPAT_DEST 621,21171
#define ATM_CAUSE_INVALID_ENDPOINT_REF 624,21254
#define ATM_CAUSE_INVALID_TRNTWRK_SEL 627,21343
#define ATM_CAUSE_TOOMANY_ADDPARTY_REQ 630,21434
#define ATM_CAUSE_INVALID_AAL_PARAM 633,21524
#define ATM_CAUSE_MANDATORY_IE_MISSING 636,21620
#define ATM_CAUSE_MSG_NOT_EXISTING 639,21720
#define ATM_CAUSE_IE_NOT_EXISTING 642,21827
#define ATM_CAUSE_INVALID_IE_CONTENTS 645,21919
#define ATM_CAUSE_INCOMPAT_MSG 648,22014
#define ATM_CAUSE_RCVRY_ON_TIMEREXPIRY 651,22094
#define ATM_CAUSE_INCORRCT_MSG_LNGTH 654,22174
#define ATM_CAUSE_PROTOCOL_ERROR 657,22257
#define ATM_CALLEDPARTYIE_ID 663,22340
typedef struct atmSig_calledPartyNumber_ atmSig_calledPartyNumber_665,22389
} atmSig_calledPartyNumber;atmSig_calledPartyNumber668,22492
#define ATMSIG_CALLEDPARTY_IESIZE 670,22521
#define ATM_CALLEDPARTY_NUM_MASK 673,22608
#define ATM_CALLEDPARTY_NUM_UKNOWN 674,22656
#define ATM_CALLEDPARTY_NUM_INTERNTL 675,22704
#define ATM_CALLEDPARTY_NUMPLAN_MASK 678,22800
#define ATM_CALLEDPARTY_NUMPLAN_ISDN 679,22848
#define ATM_CALLEDPARTY_NUMPLAN_NSAP 680,22896
#define ATM_CALLEDPARTY_PRESCR_IND 683,22994
#define ATM_CALLINGPARTYIE_ID 688,23077
typedef struct atmSig_callingPartyNumber_ atmSig_callingPartyNumber_690,23131
} atmSig_callingPartyNumber;atmSig_callingPartyNumber694,23312
#define ATMSIG_CALLINGPARTY_IESIZE 696,23342
#define ATM_CALLINGPARTYIE_PRESIND_MASK 699,23438
#define ATM_CALLINGPARTYIE_PRESIND_ALLOWED 700,23491
#define ATM_CALLINGPARTYIE_PRESIND_RESTRCTD 701,23544
#define ATM_CALLINGPARTYIE_PRESIND_NOTAVAIL 702,23597
#define ATM_CALLINGPARTYIE_PRESIND_RSRVD 703,23650
#define ATM_CALLINGPARTYIE_SCREENIND_MASK 706,23730
#define ATM_CALLINGPARTYIE_SCREENIND_NONE 707,23783
#define ATM_CALLINGPARTYIE_SCREENIND_PASSED 708,23836
#define ATM_CALLINGPARTYIE_SCREENIND_FAILED 709,23889
#define ATM_CALLINGPARTYIE_SCREENIND_NETWRK 710,23942
#define ATM_BROADBAND_TYPE_ISO 718,24043
#define ATM_BROADBAND_TYPE_USER 719,24091
#define ATM_BROADBAND_TYPE_HIGHLYR 720,24139
#define ATM_BROADBAND_TYPE_VENDOR 721,24187
typedef struct atmSig_restartIndicatorIe_atmSig_restartIndicatorIe_728,24269
} atmSig_restartIndicatorIe;atmSig_restartIndicatorIe732,24330
#define ATMSIG_RESTARTINDICATOR_IESIZE 734,24360
#define ATM_RESTART_CLASS_MASK 738,24419
#define ATM_RESTART_CLASS_ONE_VC 739,24464
#define ATM_RESTART_CLASS_ALL_VC 740,24509
#define ATM_TRANSIT_NETID 748,24631
#define ATM_TRANSIT_NETID_PLAN 751,24711
#define ATM_TRANSIT_NETID_LENGTH 754,24830
#define ATM_OP_FWD_PEAK_CLP0 760,24902
#define ATM_OP_BWD_PEAK_CLP0 761,24943
#define ATM_OP_FWD_PEAK_CLP01 762,24983
#define ATM_OP_BWD_PEAK_CLP01 763,25023
#define ATM_OP_FWD_SUS_CLP0 764,25063
#define ATM_OP_BWD_SUS_CLP0 765,25103
#define ATM_OP_FWD_SUS_CLP01 766,25143
#define ATM_OP_BWD_SUS_CLP01 767,25183
#define ATM_OP_FWD_BURST_CLP0 768,25223
#define ATM_OP_BWD_BURST_CLP0 769,25263
#define ATM_OP_FWD_BURST_CLP01 770,25303
#define ATM_OP_BWD_BURST_CLP01 771,25343
#define ATM_UCR_FWD_PEAK_CLP0 774,25385
#define ATM_UCR_BWD_PEAK_CLP0 775,25433
#define ATM_UCR_FWD_PEAK_CLP01 776,25480
#define ATM_UCR_BWD_PEAK_CLP01 777,25527
#define ATM_UCR_FWD_SUS_CLP0 778,25574
#define ATM_UCR_BWD_SUS_CLP0 779,25621
#define ATM_UCR_FWD_SUS_CLP01 780,25668
#define ATM_UCR_BWD_SUS_CLP01 781,25715
#define ATM_UCR_FWD_BURST_CLP0 782,25762
#define ATM_UCR_BWD_BURST_CLP0 783,25809
#define ATM_UCR_FWD_BURST_CLP01 784,25856
#define ATM_UCR_BWD_BURST_CLP01 785,25903
#define ATM_UCR_BEST_EFFORT_IND 786,25950
#define ATM_UCR_TRMGMT_OPTIONS_ID 787,25991
#define ATM_UCR_TAGGING_FWD 789,26033
#define ATM_UCR_TAGGING_BWD 790,26074
#define ATM_UCR_VALUE_SIZE 791,26115
#define ATM_UCR_BESTEFFORT_LNGTH 794,26225
#define ATMSIG_UCRID_LENGTH 796,26264
#define ATMSIG_UCRID_TRMGMT_LENGTH 797,26302
typedef union atmSig_userCellRate_ atmSig_userCellRate_799,26341
} atmSig_userCellRate;atmSig_userCellRate802,26413
typedef struct atmSig_lowLayerIe_ atmSig_lowLayerIe_805,26438
} atmSig_lowLayerIe;atmSig_lowLayerIe810,26551
#define ATMSIG_LLAYER3_LENGTH 812,26573
#define ATMSIG_LLAYER3_ISO9577 813,26608
#define ATMSIG_LLAYER3_IPI 814,26645
#define ATMSIG_LLAYER3_SNAPID 815,26684
#define ATMSIG_LLAYER3_ID_OFFSET 817,26729
#define ATMSIG_LLAYER3_IPI_OFFSET 818,26772
#define ATMSIG_LLAYER3_SNAPID_OFFSET 819,26815
#define ATMSIG_LLAYER3_PID_OFFSET 820,26858
#define ATMSIG_LLAYER2_LENGTH 822,26902
#define ATMSIG_LLAYER2_ID 823,26936
#define ATMSIG_LLAYER_LENGTH 825,26974
#define ATM_MAX_BLLI_NUM 828,27100
#define ATMSIG_REPEAT_INDICATION 831,27168
typedef struct atmSig_endpointRefIe_ atmSig_endpointRefIe_837,27266
} atmSig_endpointRefIe;atmSig_endpointRefIe840,27358
#define ATMSIG_ENDPOINT_REF_IESIZE 842,27383
#define ATMSIG_ENDPOINT_REF_TYPE 844,27425
#define ATMSIG_ENDPOINT_REF_FLAG 845,27466
#define ATMSIG_ENDPOINT_REF_MASK 846,27507
typedef struct atmSig_endpointStateIe_ atmSig_endpointStateIe_850,27575
} atmSig_endpointStateIe;atmSig_endpointStateIe852,27640
#define ATMSIG_ENDPOINT_STATE_IESIZE 854,27667
#define ATMSIG_ENDPOINT_STATE_IE_MASK 855,27710
#define ATMSIG_ENDPOINT_STATE_NULL 859,27778
#define ATMSIG_ENDPOINT_STATE_ADD_PARTY_INIT 860,27832
#define ATMSIG_ENDPOINT_STATE_ADD_PARTY_RCVD 861,27886
#define ATMSIG_ENDPOINT_STATE_DROP_PARTY_INIT 862,27940
#define ATMSIG_ENDPOINT_STATE_DROP_PARTY_RCVD 863,27994
#define ATMSIG_ENDPOINT_STATE_ACTIVE 864,28048