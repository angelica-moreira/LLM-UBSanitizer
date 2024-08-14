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
struct tcf_exts {scalar_t__ nr_actions; scalar_t__ actions; } ;

/* Variables and functions */
 int /*<<< orphan*/  TCA_ACT_UNBIND ; 
 int /*<<< orphan*/  kfree (scalar_t__) ; 
 int /*<<< orphan*/  tcf_action_destroy (scalar_t__,int /*<<< orphan*/ ) ; 

void tcf_exts_destroy(struct tcf_exts *exts)
{
#ifdef CONFIG_NET_CLS_ACT
	if (exts->actions) {
		tcf_action_destroy(exts->actions, TCA_ACT_UNBIND);
		kfree(exts->actions);
	}
	exts->nr_actions = 0;
#endif
}