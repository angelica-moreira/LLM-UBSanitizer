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
struct virtqueue {int /*<<< orphan*/  vdev; } ;
struct virtio_scsi {int /*<<< orphan*/  ctrl_vq; } ;
struct Scsi_Host {int dummy; } ;

/* Variables and functions */
 struct virtio_scsi* shost_priv (struct Scsi_Host*) ; 
 struct Scsi_Host* virtio_scsi_host (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virtscsi_complete_free ; 
 int /*<<< orphan*/  virtscsi_vq_done (struct virtio_scsi*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void virtscsi_ctrl_done(struct virtqueue *vq)
{
	struct Scsi_Host *sh = virtio_scsi_host(vq->vdev);
	struct virtio_scsi *vscsi = shost_priv(sh);

	virtscsi_vq_done(vscsi, &vscsi->ctrl_vq, virtscsi_complete_free);
}