#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct xt_tgdtor_param {TYPE_1__* target; int /*<<< orphan*/  family; int /*<<< orphan*/  targinfo; } ;
struct TYPE_5__ {TYPE_1__* target; } ;
struct TYPE_6__ {TYPE_2__ kernel; } ;
struct xt_entry_target {int /*<<< orphan*/  data; TYPE_3__ u; } ;
struct arpt_entry {int /*<<< orphan*/  counters; } ;
struct TYPE_4__ {int /*<<< orphan*/  me; int /*<<< orphan*/  (* destroy ) (struct xt_tgdtor_param*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  NFPROTO_ARP ; 
 struct xt_entry_target* arpt_get_target (struct arpt_entry*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct xt_tgdtor_param*) ; 
 int /*<<< orphan*/  xt_percpu_counter_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void cleanup_entry(struct arpt_entry *e)
{
	struct xt_tgdtor_param par;
	struct xt_entry_target *t;

	t = arpt_get_target(e);
	par.target   = t->u.kernel.target;
	par.targinfo = t->data;
	par.family   = NFPROTO_ARP;
	if (par.target->destroy != NULL)
		par.target->destroy(&par);
	module_put(par.target->me);
	xt_percpu_counter_free(&e->counters);
}