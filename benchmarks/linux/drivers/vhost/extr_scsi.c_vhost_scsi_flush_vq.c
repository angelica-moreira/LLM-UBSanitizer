#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct vhost_scsi {TYPE_2__* vqs; } ;
struct TYPE_3__ {int /*<<< orphan*/  poll; } ;
struct TYPE_4__ {TYPE_1__ vq; } ;

/* Variables and functions */
 int /*<<< orphan*/  vhost_poll_flush (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void vhost_scsi_flush_vq(struct vhost_scsi *vs, int index)
{
	vhost_poll_flush(&vs->vqs[index].vq.poll);
}