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
struct nfqnl_instance {int dummy; } ;
struct nfnl_queue_net {int /*<<< orphan*/  instances_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __instance_destroy (struct nfqnl_instance*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
instance_destroy(struct nfnl_queue_net *q, struct nfqnl_instance *inst)
{
	spin_lock(&q->instances_lock);
	__instance_destroy(inst);
	spin_unlock(&q->instances_lock);
}