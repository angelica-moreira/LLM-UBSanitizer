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
typedef  scalar_t__ s64 ;

/* Variables and functions */
 int EIO ; 
 scalar_t__ opal_xive_set_queue_state (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

int xive_native_set_queue_state(u32 vp_id, u32 prio, u32 qtoggle, u32 qindex)
{
	s64 rc;

	rc = opal_xive_set_queue_state(vp_id, prio, qtoggle, qindex);
	if (rc) {
		pr_err("OPAL failed to set queue state for VCPU %d/%d : %lld\n",
		       vp_id, prio, rc);
		return -EIO;
	}

	return 0;
}