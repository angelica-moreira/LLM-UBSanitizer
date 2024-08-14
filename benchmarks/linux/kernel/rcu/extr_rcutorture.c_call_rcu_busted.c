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
struct rcu_head {int dummy; } ;
typedef  int /*<<< orphan*/  (* rcu_callback_t ) (struct rcu_head*) ;

/* Variables and functions */

__attribute__((used)) static void
call_rcu_busted(struct rcu_head *head, rcu_callback_t func)
{
	/* This is a deliberate bug for testing purposes only! */
	func(head);
}