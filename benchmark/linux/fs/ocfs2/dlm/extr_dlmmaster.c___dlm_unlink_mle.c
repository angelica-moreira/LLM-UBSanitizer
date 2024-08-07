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
struct dlm_master_list_entry {int /*<<< orphan*/  master_hash_node; } ;
struct dlm_ctxt {int /*<<< orphan*/  master_lock; int /*<<< orphan*/  spinlock; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert_spin_locked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hlist_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hlist_unhashed (int /*<<< orphan*/ *) ; 

void __dlm_unlink_mle(struct dlm_ctxt *dlm, struct dlm_master_list_entry *mle)
{
	assert_spin_locked(&dlm->spinlock);
	assert_spin_locked(&dlm->master_lock);

	if (!hlist_unhashed(&mle->master_hash_node))
		hlist_del_init(&mle->master_hash_node);
}