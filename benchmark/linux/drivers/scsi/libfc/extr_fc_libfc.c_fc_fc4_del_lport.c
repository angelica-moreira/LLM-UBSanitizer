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
struct fc_lport {int /*<<< orphan*/  lport_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  FC_LPORT_EV_DEL ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct fc_lport*) ; 
 int /*<<< orphan*/  fc_lport_notifier_head ; 
 int /*<<< orphan*/  fc_prov_mutex ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void fc_fc4_del_lport(struct fc_lport *lport)
{
	mutex_lock(&fc_prov_mutex);
	list_del(&lport->lport_list);
	blocking_notifier_call_chain(&fc_lport_notifier_head,
				     FC_LPORT_EV_DEL, lport);
	mutex_unlock(&fc_prov_mutex);
}