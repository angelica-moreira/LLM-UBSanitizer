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
struct TYPE_2__ {int /*<<< orphan*/  (* cause_ipi ) (int) ;} ;

/* Variables and functions */
 scalar_t__ doorbell_try_core_ipi (int) ; 
 TYPE_1__* icp_ops ; 
 int /*<<< orphan*/  stub1 (int) ; 

__attribute__((used)) static void smp_pseries_cause_ipi(int cpu)
{
	/* POWER9 should not use this handler */
	if (doorbell_try_core_ipi(cpu))
		return;

	icp_ops->cause_ipi(cpu);
}