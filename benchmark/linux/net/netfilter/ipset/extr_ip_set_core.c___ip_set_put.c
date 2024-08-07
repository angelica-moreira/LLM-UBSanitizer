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
struct ip_set {scalar_t__ ref; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  ip_set_ref_lock ; 
 int /*<<< orphan*/  write_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void
__ip_set_put(struct ip_set *set)
{
	write_lock_bh(&ip_set_ref_lock);
	BUG_ON(set->ref == 0);
	set->ref--;
	write_unlock_bh(&ip_set_ref_lock);
}