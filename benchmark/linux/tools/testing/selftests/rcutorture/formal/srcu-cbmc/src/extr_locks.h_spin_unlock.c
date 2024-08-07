#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  internal_lock; } ;
typedef  TYPE_1__ spinlock_t ;

/* Variables and functions */
 int /*<<< orphan*/  lock_impl_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  preempt_enable () ; 

__attribute__((used)) static inline void spin_unlock(spinlock_t *lock)
{
#ifndef NO_SYNC_SMP_MB
	lock_impl_unlock(&lock->internal_lock);
	preempt_enable();
#endif
}