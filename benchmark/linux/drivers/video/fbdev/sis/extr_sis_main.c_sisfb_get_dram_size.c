#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
struct sis_video_info {int video_size; int UMAsize; int LFBsize; int chip; int revision_id; int /*<<< orphan*/  nbridge; } ;

/* Variables and functions */
 int /*<<< orphan*/  SISCR ; 
 int /*<<< orphan*/  SISSR ; 
#define  SIS_300 146 
#define  SIS_315 145 
#define  SIS_315H 144 
#define  SIS_315PRO 143 
#define  SIS_330 142 
#define  SIS_340 141 
#define  SIS_540 140 
#define  SIS_550 139 
#define  SIS_630 138 
#define  SIS_650 137 
#define  SIS_660 136 
#define  SIS_661 135 
#define  SIS_730 134 
#define  SIS_740 133 
#define  SIS_741 132 
#define  SIS_760 131 
#define  SIS_761 130 
 int SiS_GetReg (int /*<<< orphan*/ ,int) ; 
#define  XGI_20 129 
#define  XGI_40 128 
 int /*<<< orphan*/  pci_read_config_byte (int /*<<< orphan*/ ,int,int*) ; 

__attribute__((used)) static int sisfb_get_dram_size(struct sis_video_info *ivideo)
{
#if defined(CONFIG_FB_SIS_300) || defined(CONFIG_FB_SIS_315)
	u8 reg;
#endif

	ivideo->video_size = 0;
	ivideo->UMAsize = ivideo->LFBsize = 0;

	switch(ivideo->chip) {
#ifdef CONFIG_FB_SIS_300
	case SIS_300:
		reg = SiS_GetReg(SISSR, 0x14);
		ivideo->video_size = ((reg & 0x3F) + 1) << 20;
		break;
	case SIS_540:
	case SIS_630:
	case SIS_730:
		if(!ivideo->nbridge)
			return -1;
		pci_read_config_byte(ivideo->nbridge, 0x63, &reg);
		ivideo->video_size = 1 << (((reg & 0x70) >> 4) + 21);
		break;
#endif
#ifdef CONFIG_FB_SIS_315
	case SIS_315H:
	case SIS_315PRO:
	case SIS_315:
		reg = SiS_GetReg(SISSR, 0x14);
		ivideo->video_size = (1 << ((reg & 0xf0) >> 4)) << 20;
		switch((reg >> 2) & 0x03) {
		case 0x01:
		case 0x03:
			ivideo->video_size <<= 1;
			break;
		case 0x02:
			ivideo->video_size += (ivideo->video_size/2);
		}
		break;
	case SIS_330:
		reg = SiS_GetReg(SISSR, 0x14);
		ivideo->video_size = (1 << ((reg & 0xf0) >> 4)) << 20;
		if(reg & 0x0c) ivideo->video_size <<= 1;
		break;
	case SIS_550:
	case SIS_650:
	case SIS_740:
		reg = SiS_GetReg(SISSR, 0x14);
		ivideo->video_size = (((reg & 0x3f) + 1) << 2) << 20;
		break;
	case SIS_661:
	case SIS_741:
		reg = SiS_GetReg(SISCR, 0x79);
		ivideo->video_size = (1 << ((reg & 0xf0) >> 4)) << 20;
		break;
	case SIS_660:
	case SIS_760:
	case SIS_761:
		reg = SiS_GetReg(SISCR, 0x79);
		reg = (reg & 0xf0) >> 4;
		if(reg)	{
			ivideo->video_size = (1 << reg) << 20;
			ivideo->UMAsize = ivideo->video_size;
		}
		reg = SiS_GetReg(SISCR, 0x78);
		reg &= 0x30;
		if(reg) {
			if(reg == 0x10) {
				ivideo->LFBsize = (32 << 20);
			} else {
				ivideo->LFBsize = (64 << 20);
			}
			ivideo->video_size += ivideo->LFBsize;
		}
		break;
	case SIS_340:
	case XGI_20:
	case XGI_40:
		reg = SiS_GetReg(SISSR, 0x14);
		ivideo->video_size = (1 << ((reg & 0xf0) >> 4)) << 20;
		if(ivideo->chip != XGI_20) {
			reg = (reg & 0x0c) >> 2;
			if(ivideo->revision_id == 2) {
				if(reg & 0x01) reg = 0x02;
				else	       reg = 0x00;
			}
			if(reg == 0x02)		ivideo->video_size <<= 1;
			else if(reg == 0x03)	ivideo->video_size <<= 2;
		}
		break;
#endif
	default:
		return -1;
	}
	return 0;
}