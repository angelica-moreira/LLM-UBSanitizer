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
struct esas2r_request {int dummy; } ;
struct esas2r_adapter {int buffered_ioctl_done; int /*<<< orphan*/  buffered_ioctl_waiter; } ;

/* Variables and functions */
 int /*<<< orphan*/  wake_up_interruptible (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void complete_buffered_ioctl_req(struct esas2r_adapter *a,
					struct esas2r_request *rq)
{
	a->buffered_ioctl_done = 1;
	wake_up_interruptible(&a->buffered_ioctl_waiter);
}