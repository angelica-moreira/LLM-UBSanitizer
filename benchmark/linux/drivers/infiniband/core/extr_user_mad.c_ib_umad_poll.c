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
struct poll_table_struct {int dummy; } ;
struct ib_umad_file {int /*<<< orphan*/  recv_list; int /*<<< orphan*/  recv_wait; } ;
struct file {struct ib_umad_file* private_data; } ;
typedef  int __poll_t ;

/* Variables and functions */
 int EPOLLIN ; 
 int EPOLLOUT ; 
 int EPOLLRDNORM ; 
 int EPOLLWRNORM ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  poll_wait (struct file*,int /*<<< orphan*/ *,struct poll_table_struct*) ; 

__attribute__((used)) static __poll_t ib_umad_poll(struct file *filp, struct poll_table_struct *wait)
{
	struct ib_umad_file *file = filp->private_data;

	/* we will always be able to post a MAD send */
	__poll_t mask = EPOLLOUT | EPOLLWRNORM;

	poll_wait(filp, &file->recv_wait, wait);

	if (!list_empty(&file->recv_list))
		mask |= EPOLLIN | EPOLLRDNORM;

	return mask;
}