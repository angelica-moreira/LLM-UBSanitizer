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
struct SiS_Private {unsigned char* VirtualRomBase; scalar_t__ ChipType; int /*<<< orphan*/  SiS_Part1Port; scalar_t__ SiS_XGIROM; scalar_t__ SiS_ROMNew; scalar_t__ SiS_UseROM; } ;

/* Variables and functions */
 scalar_t__ SIS_330 ; 
 scalar_t__ SIS_661 ; 
 int /*<<< orphan*/  SiS_SetReg (int /*<<< orphan*/ ,int,unsigned short) ; 
 size_t VB310Data_1_2_Offset ; 
 scalar_t__ XGI_20 ; 
 scalar_t__ XGI_40 ; 

__attribute__((used)) static void
SiS_ResetVB(struct SiS_Private *SiS_Pr)
{
#ifdef CONFIG_FB_SIS_315
   unsigned char  *ROMAddr = SiS_Pr->VirtualRomBase;
   unsigned short temp;

   /* VB programming clock */
   if(SiS_Pr->SiS_UseROM) {
      if(SiS_Pr->ChipType < SIS_330) {
	 temp = ROMAddr[VB310Data_1_2_Offset] | 0x40;
	 if(SiS_Pr->SiS_ROMNew) temp = ROMAddr[0x80] | 0x40;
	 SiS_SetReg(SiS_Pr->SiS_Part1Port,0x02,temp);
      } else if(SiS_Pr->ChipType >= SIS_661 && SiS_Pr->ChipType < XGI_20) {
	 temp = ROMAddr[0x7e] | 0x40;
	 if(SiS_Pr->SiS_ROMNew) temp = ROMAddr[0x80] | 0x40;
	 SiS_SetReg(SiS_Pr->SiS_Part1Port,0x02,temp);
      }
   } else if(SiS_Pr->ChipType >= XGI_40) {
      temp = 0x40;
      if(SiS_Pr->SiS_XGIROM) temp |= ROMAddr[0x7e];
      /* Can we do this on any chipset? */
      SiS_SetReg(SiS_Pr->SiS_Part1Port,0x02,temp);
   }
#endif
}