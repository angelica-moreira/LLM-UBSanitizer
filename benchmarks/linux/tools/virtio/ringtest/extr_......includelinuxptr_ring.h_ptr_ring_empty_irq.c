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
struct ptr_ring {int /*<<< orphan*/  consumer_lock; } ;

/* Variables and functions */
 int __ptr_ring_empty (struct ptr_ring*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool ptr_ring_empty_irq(struct ptr_ring *r)
{
	bool ret;

	spin_lock_irq(&r->consumer_lock);
	ret = __ptr_ring_empty(r);
	spin_unlock_irq(&r->consumer_lock);

	return ret;
}