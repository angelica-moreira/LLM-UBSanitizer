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
struct pulse_elem {int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int /*<<< orphan*/  DFS_POOL_STAT_DEC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pool_lock ; 
 int /*<<< orphan*/  pulse_pool ; 
 int /*<<< orphan*/  pulse_used ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pool_put_pulse_elem(struct pulse_elem *pe)
{
	spin_lock_bh(&pool_lock);
	list_add(&pe->head, &pulse_pool);
	DFS_POOL_STAT_DEC(pulse_used);
	spin_unlock_bh(&pool_lock);
}