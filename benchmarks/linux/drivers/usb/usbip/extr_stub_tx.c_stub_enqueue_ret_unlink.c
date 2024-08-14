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
struct stub_unlink {int /*<<< orphan*/  list; void* status; void* seqnum; } ;
struct stub_device {int /*<<< orphan*/  unlink_tx; int /*<<< orphan*/  ud; } ;
typedef  void* __u32 ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  VDEV_EVENT_ERROR_MALLOC ; 
 struct stub_unlink* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usbip_event_add (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void stub_enqueue_ret_unlink(struct stub_device *sdev, __u32 seqnum,
			     __u32 status)
{
	struct stub_unlink *unlink;

	unlink = kzalloc(sizeof(struct stub_unlink), GFP_ATOMIC);
	if (!unlink) {
		usbip_event_add(&sdev->ud, VDEV_EVENT_ERROR_MALLOC);
		return;
	}

	unlink->seqnum = seqnum;
	unlink->status = status;

	list_add_tail(&unlink->list, &sdev->unlink_tx);
}