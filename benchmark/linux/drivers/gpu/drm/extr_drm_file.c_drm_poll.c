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
struct file {struct drm_file* private_data; } ;
struct drm_file {int /*<<< orphan*/  event_list; int /*<<< orphan*/  event_wait; } ;
typedef  int __poll_t ;

/* Variables and functions */
 int EPOLLIN ; 
 int EPOLLRDNORM ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  poll_wait (struct file*,int /*<<< orphan*/ *,struct poll_table_struct*) ; 

__poll_t drm_poll(struct file *filp, struct poll_table_struct *wait)
{
	struct drm_file *file_priv = filp->private_data;
	__poll_t mask = 0;

	poll_wait(filp, &file_priv->event_wait, wait);

	if (!list_empty(&file_priv->event_list))
		mask |= EPOLLIN | EPOLLRDNORM;

	return mask;
}