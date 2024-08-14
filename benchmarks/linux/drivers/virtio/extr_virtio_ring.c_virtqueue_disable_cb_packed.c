#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* driver; } ;
struct TYPE_6__ {scalar_t__ event_flags_shadow; TYPE_2__ vring; } ;
struct vring_virtqueue {TYPE_3__ packed; } ;
struct virtqueue {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 scalar_t__ VRING_PACKED_EVENT_FLAG_DISABLE ; 
 int /*<<< orphan*/  cpu_to_le16 (scalar_t__) ; 
 struct vring_virtqueue* to_vvq (struct virtqueue*) ; 

__attribute__((used)) static void virtqueue_disable_cb_packed(struct virtqueue *_vq)
{
	struct vring_virtqueue *vq = to_vvq(_vq);

	if (vq->packed.event_flags_shadow != VRING_PACKED_EVENT_FLAG_DISABLE) {
		vq->packed.event_flags_shadow = VRING_PACKED_EVENT_FLAG_DISABLE;
		vq->packed.vring.driver->flags =
			cpu_to_le16(vq->packed.event_flags_shadow);
	}
}