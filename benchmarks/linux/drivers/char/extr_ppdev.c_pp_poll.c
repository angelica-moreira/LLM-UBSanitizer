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
struct pp_struct {int /*<<< orphan*/  irqc; int /*<<< orphan*/  irq_wait; } ;
struct file {struct pp_struct* private_data; } ;
typedef  int /*<<< orphan*/  poll_table ;
typedef  int __poll_t ;

/* Variables and functions */
 int EPOLLIN ; 
 int EPOLLRDNORM ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  poll_wait (struct file*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static __poll_t pp_poll(struct file *file, poll_table *wait)
{
	struct pp_struct *pp = file->private_data;
	__poll_t mask = 0;

	poll_wait(file, &pp->irq_wait, wait);
	if (atomic_read(&pp->irqc))
		mask |= EPOLLIN | EPOLLRDNORM;

	return mask;
}