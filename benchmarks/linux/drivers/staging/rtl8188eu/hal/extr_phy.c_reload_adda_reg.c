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
typedef  size_t u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bMaskDWord ; 
 int /*<<< orphan*/  phy_set_bb_reg (struct adapter*,size_t,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static void reload_adda_reg(struct adapter *adapt, u32 *adda_reg,
			    u32 *backup, u32 regiester_num)
{
	u32 i;

	for (i = 0; i < regiester_num; i++)
		phy_set_bb_reg(adapt, adda_reg[i], bMaskDWord, backup[i]);
}