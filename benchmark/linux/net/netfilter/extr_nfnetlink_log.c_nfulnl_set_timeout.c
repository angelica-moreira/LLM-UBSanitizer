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
typedef  int /*<<< orphan*/  u_int32_t ;
struct nfulnl_instance {int /*<<< orphan*/  lock; int /*<<< orphan*/  flushtimeout; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
nfulnl_set_timeout(struct nfulnl_instance *inst, u_int32_t timeout)
{
	spin_lock_bh(&inst->lock);
	inst->flushtimeout = timeout;
	spin_unlock_bh(&inst->lock);
}