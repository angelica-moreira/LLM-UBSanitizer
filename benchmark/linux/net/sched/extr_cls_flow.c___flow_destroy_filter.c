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
struct flow_filter {int /*<<< orphan*/  exts; int /*<<< orphan*/  ematches; int /*<<< orphan*/  perturb_timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct flow_filter*) ; 
 int /*<<< orphan*/  tcf_em_tree_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tcf_exts_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tcf_exts_put_net (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __flow_destroy_filter(struct flow_filter *f)
{
	del_timer_sync(&f->perturb_timer);
	tcf_exts_destroy(&f->exts);
	tcf_em_tree_destroy(&f->ematches);
	tcf_exts_put_net(&f->exts);
	kfree(f);
}