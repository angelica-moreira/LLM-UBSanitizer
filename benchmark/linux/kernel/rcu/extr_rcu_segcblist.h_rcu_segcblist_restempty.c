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
struct rcu_segcblist {int /*<<< orphan*/ * tails; } ;

/* Variables and functions */
 int /*<<< orphan*/ * READ_ONCE (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool rcu_segcblist_restempty(struct rcu_segcblist *rsclp, int seg)
{
	return !READ_ONCE(*READ_ONCE(rsclp->tails[seg]));
}