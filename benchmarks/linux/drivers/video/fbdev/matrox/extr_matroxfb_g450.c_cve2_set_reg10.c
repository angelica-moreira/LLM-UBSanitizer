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
struct matrox_fb_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  matroxfb_DAC_lock_irqsave (unsigned long) ; 
 int /*<<< orphan*/  matroxfb_DAC_out (struct matrox_fb_info*,int,int) ; 
 int /*<<< orphan*/  matroxfb_DAC_unlock_irqrestore (unsigned long) ; 

__attribute__((used)) static void cve2_set_reg10(struct matrox_fb_info *minfo, int reg, int val)
{
	unsigned long flags;

	matroxfb_DAC_lock_irqsave(flags);
	matroxfb_DAC_out(minfo, 0x87, reg);
	matroxfb_DAC_out(minfo, 0x88, val >> 2);
	matroxfb_DAC_out(minfo, 0x87, reg + 1);
	matroxfb_DAC_out(minfo, 0x88, val & 3);
	matroxfb_DAC_unlock_irqrestore(flags);
}