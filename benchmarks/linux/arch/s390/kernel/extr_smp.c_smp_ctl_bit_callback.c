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
struct ec_creg_mask_parms {size_t cr; unsigned long andval; unsigned long orval; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ctl_load (unsigned long*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __ctl_store (unsigned long*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void smp_ctl_bit_callback(void *info)
{
	struct ec_creg_mask_parms *pp = info;
	unsigned long cregs[16];

	__ctl_store(cregs, 0, 15);
	cregs[pp->cr] = (cregs[pp->cr] & pp->andval) | pp->orval;
	__ctl_load(cregs, 0, 15);
}