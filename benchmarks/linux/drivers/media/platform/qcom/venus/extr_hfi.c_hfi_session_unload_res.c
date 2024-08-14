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
struct venus_inst {scalar_t__ state; int /*<<< orphan*/  done; TYPE_1__* core; } ;
struct hfi_ops {int (* session_release_res ) (struct venus_inst*) ;} ;
struct TYPE_2__ {struct hfi_ops* ops; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ INST_RELEASE_RESOURCES ; 
 scalar_t__ INST_STOP ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int stub1 (struct venus_inst*) ; 
 int wait_session_msg (struct venus_inst*) ; 

int hfi_session_unload_res(struct venus_inst *inst)
{
	const struct hfi_ops *ops = inst->core->ops;
	int ret;

	if (inst->state != INST_STOP)
		return -EINVAL;

	reinit_completion(&inst->done);

	ret = ops->session_release_res(inst);
	if (ret)
		return ret;

	ret = wait_session_msg(inst);
	if (ret)
		return ret;

	inst->state = INST_RELEASE_RESOURCES;

	return 0;
}