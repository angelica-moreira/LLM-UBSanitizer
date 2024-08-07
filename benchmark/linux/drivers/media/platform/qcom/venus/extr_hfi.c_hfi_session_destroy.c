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
struct venus_inst {int /*<<< orphan*/  list; struct venus_core* core; } ;
struct venus_core {int /*<<< orphan*/  lock; int /*<<< orphan*/  insts_count; } ;

/* Variables and functions */
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up_var (int /*<<< orphan*/ *) ; 

void hfi_session_destroy(struct venus_inst *inst)
{
	struct venus_core *core = inst->core;

	mutex_lock(&core->lock);
	list_del_init(&inst->list);
	if (atomic_dec_and_test(&core->insts_count))
		wake_up_var(&core->insts_count);
	mutex_unlock(&core->lock);
}