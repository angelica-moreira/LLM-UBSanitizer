#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  ippdexpcr; } ;

/* Variables and functions */
 int /*<<< orphan*/  clrbits32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_1__* rcpm_v1_regs ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rcpm_v1_set_ip_power(bool enable, u32 mask)
{
	if (enable)
		setbits32(&rcpm_v1_regs->ippdexpcr, mask);
	else
		clrbits32(&rcpm_v1_regs->ippdexpcr, mask);
}