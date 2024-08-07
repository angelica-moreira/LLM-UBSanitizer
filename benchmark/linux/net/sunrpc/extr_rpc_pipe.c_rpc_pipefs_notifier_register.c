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
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int blocking_notifier_chain_cond_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  rpc_pipefs_notifier_list ; 

int rpc_pipefs_notifier_register(struct notifier_block *nb)
{
	return blocking_notifier_chain_cond_register(&rpc_pipefs_notifier_list, nb);
}