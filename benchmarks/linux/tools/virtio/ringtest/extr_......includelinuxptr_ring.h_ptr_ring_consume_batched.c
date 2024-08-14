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
 int __ptr_ring_consume_batched (struct ptr_ring*,void**,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int ptr_ring_consume_batched(struct ptr_ring *r,
					   void **array, int n)
{
	int ret;

	spin_lock(&r->consumer_lock);
	ret = __ptr_ring_consume_batched(r, array, n);
	spin_unlock(&r->consumer_lock);

	return ret;
}