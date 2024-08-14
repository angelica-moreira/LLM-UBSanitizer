#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  s64 ;
typedef  int /*<<< orphan*/  raw_spinlock_t ;
struct TYPE_4__ {int /*<<< orphan*/  counter; } ;
typedef  TYPE_1__ atomic64_t ;

/* Variables and functions */
 int /*<<< orphan*/ * lock_addr (TYPE_1__*) ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

s64 atomic64_xchg(atomic64_t *v, s64 new)
{
	unsigned long flags;
	raw_spinlock_t *lock = lock_addr(v);
	s64 val;

	raw_spin_lock_irqsave(lock, flags);
	val = v->counter;
	v->counter = new;
	raw_spin_unlock_irqrestore(lock, flags);
	return val;
}