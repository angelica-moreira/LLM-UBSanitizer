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
struct rcu_cblist {int /*<<< orphan*/  len; } ;

/* Variables and functions */
 long READ_ONCE (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline long rcu_cblist_n_cbs(struct rcu_cblist *rclp)
{
	return READ_ONCE(rclp->len);
}