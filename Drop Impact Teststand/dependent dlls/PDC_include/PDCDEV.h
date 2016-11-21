/*
 *	PDCDEV.h
 *	Photron Device Control SDK
 *	Device Definition
 *
 *	Copyright (C) 2006-2012 PHOTRON LIMITED
 */

#ifndef	_PDC_DEV_H_
#define	_PDC_DEV_H_

/*	Device Code	*/
#define	PDC_DEVTYPE_UNKNOWN					0x00000000
#define	PDC_DEVTYPE_FCAM_VIRTUAL			0x00000001
#define	PDC_DEVTYPE_FCAM_MAX				0x00000002
#define	PDC_DEVTYPE_FCAM_APX				0x00000002
#define	PDC_DEVTYPE_FCAM_NEO				0x00000003
#define	PDC_DEVTYPE_FCAM_UL512				0x00000003
#define	PDC_DEVTYPE_FCAM_MAX_II				0x00000004
#define	PDC_DEVTYPE_FCAM_APX_II				0x00000004
#define	PDC_DEVTYPE_FCAM_APXRS				0x00000005
#define	PDC_DEVTYPE_FCAM_MH4				0x00000006
#define	PDC_DEVTYPE_FCAM_SA1				0x00000007
#define	PDC_DEVTYPE_FCAM_MC1				0x00000008
#define	PDC_DEVTYPE_FCAM_SA2				0x00000009
#define	PDC_DEVTYPE_FCAM_SA3				0x0000000a
#define	PDC_DEVTYPE_FCAM_CT3				0x0000000a
#define	PDC_DEVTYPE_FCAM_MC2				0x0000000b
#define	PDC_DEVTYPE_FCAM_SA5				0x0000000c
#define	PDC_DEVTYPE_FCAM_BC2				0x0000000d
#define	PDC_DEVTYPE_FCAM_SA4				0x0000000e
#define	PDC_DEVTYPE_FCAM_SAX				0x0000000f
#define	PDC_DEVTYPE_FCAM_SA6				0x00000010

#define	PDC_DEVTYPE_FCAM_HMP01				0x00000011
#define PDC_DEVTYPE_FCAM_UT					0x00000012
#define PDC_DEVTYPE_FCAM_SA7				0x00000013
#define PDC_DEVTYPE_FCAM_8605P				0x00000014
#define	PDC_DEVTYPE_FCAM_SAX_B				0x00000015
#define	PDC_DEVTYPE_FCAM_SA8				0x00000016
#define	PDC_DEVTYPE_FCAM_UX					0x00000017
#define	PDC_DEVTYPE_FCAM_SAZ				0x00000018
#define	PDC_DEVTYPE_FCAM_UX50				0x00000019
#define	PDC_DEVTYPE_FCAM_TX					0x0000001a
#define	PDC_DEVTYPE_FCAM_ISAS				0x0000001b
#define PDC_DEVTYPE_FCAM_WX					0x0000001c
#define PDC_DEVTYPE_FCAM_WX50				0x0000001d
#define PDC_DEVTYPE_FCAM_AX200				0x0000001e
#define PDC_DEVTYPE_FCAM_AX50				0x0000001f
#define PDC_DEVTYPE_FCAM_AX100				0x00000020

#define	PDC_DEVTYPE_FCAM_PCI2				0x00000101
#define	PDC_DEVTYPE_FCAM_512PCI				0x00000102
#define	PDC_DEVTYPE_FCAM_SUSPCI				0x00000103
#define	PDC_DEVTYPE_FCAM_1024PCI			0x00000104
#define	PDC_DEVTYPE_FCAM_1024PCIE			0x00000105
#define PDC_DEVTYPE_FCAM_DVR				0x00000200
#define	PDC_DEVTYPE_IDPEXPRESS				0x00000400
#define	PDC_DEVTYPE_FDM_PCIE_CL				0x00001000
#define	PDC_DEVTYPE_FCAM_SP8				0x00010000
#define	PDC_DEVTYPE_PCAM_SPEEDER			0x00100000
#define	PDC_DEVTYPE_PCAM_SPEEDER_V2			0x00100001
#define	PDC_DEVTYPE_PI5						0x00000410


/*	Interface Code	*/
#define	PDC_INTTYPE_VIRTUAL					0x00000001
#define	PDC_INTTYPE_G_ETHER					0x00000002
#define	PDC_INTTYPE_IEEE1394				0x00000003
#define	PDC_INTTYPE_OPTICAL					0x00000004
#define	PDC_INTTYPE_USB2					0x00000005
#define	PDC_INTTYPE_PCI						0x00000100
#define PDC_INTTYPE_DVR						0x00000200

#endif	/*	_PDC_DEV_H_	*/

