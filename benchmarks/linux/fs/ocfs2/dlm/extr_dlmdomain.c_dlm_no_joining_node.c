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
struct dlm_ctxt {scalar_t__ joining_node; int /*<<< orphan*/  spinlock; } ;

/* Variables and functions */
 scalar_t__ DLM_LOCK_RES_OWNER_UNKNOWN ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int dlm_no_joining_node(struct dlm_ctxt *dlm)
{
	int ret;

	spin_lock(&dlm->spinlock);
	ret = dlm->joining_node == DLM_LOCK_RES_OWNER_UNKNOWN;
	spin_unlock(&dlm->spinlock);

	return ret;
}