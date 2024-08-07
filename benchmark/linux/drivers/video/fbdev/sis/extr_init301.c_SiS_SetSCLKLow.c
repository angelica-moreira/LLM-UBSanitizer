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
struct SiS_Private {int /*<<< orphan*/  SiS_DDC_NClk; int /*<<< orphan*/  SiS_DDC_Index; int /*<<< orphan*/  SiS_DDC_Port; } ;

/* Variables and functions */
 int /*<<< orphan*/  SiS_DDC2Delay (struct SiS_Private*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SiS_I2CDELAYSHORT ; 
 int /*<<< orphan*/  SiS_SetRegANDOR (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static unsigned short
SiS_SetSCLKLow(struct SiS_Private *SiS_Pr)
{
  SiS_SetRegANDOR(SiS_Pr->SiS_DDC_Port,
		  SiS_Pr->SiS_DDC_Index,
		  SiS_Pr->SiS_DDC_NClk,
		  0x00);					/* SetSCLKLow()  */
  SiS_DDC2Delay(SiS_Pr,SiS_I2CDELAYSHORT);
  return 0;
}