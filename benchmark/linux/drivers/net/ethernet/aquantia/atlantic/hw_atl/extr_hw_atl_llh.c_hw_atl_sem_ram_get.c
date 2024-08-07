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
typedef  int /*<<< orphan*/  u32 ;
struct aq_hw_s {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HW_ATL_FW_SM_RAM ; 
 int /*<<< orphan*/  hw_atl_reg_glb_cpu_sem_get (struct aq_hw_s*,int /*<<< orphan*/ ) ; 

u32 hw_atl_sem_ram_get(struct aq_hw_s *self)
{
	return hw_atl_reg_glb_cpu_sem_get(self, HW_ATL_FW_SM_RAM);
}