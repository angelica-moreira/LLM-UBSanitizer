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
struct sched_shutdown {int reason; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int HYPERVISOR_sched_op (int /*<<< orphan*/ ,struct sched_shutdown*) ; 
 int /*<<< orphan*/  SCHEDOP_shutdown ; 

void xen_reboot(int reason)
{
	struct sched_shutdown r = { .reason = reason };
	int rc;

	rc = HYPERVISOR_sched_op(SCHEDOP_shutdown, &r);
	BUG_ON(rc);
}