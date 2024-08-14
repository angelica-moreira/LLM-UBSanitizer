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

/* Variables and functions */
 int /*<<< orphan*/  allocated_irqs ; 
 int /*<<< orphan*/  bitmap_set (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sparse_irq_lock ; 

void irq_mark_irq(unsigned int irq)
{
	mutex_lock(&sparse_irq_lock);
	bitmap_set(allocated_irqs, irq, 1);
	mutex_unlock(&sparse_irq_lock);
}