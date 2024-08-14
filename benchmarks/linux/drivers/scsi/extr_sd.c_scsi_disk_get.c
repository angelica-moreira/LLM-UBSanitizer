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
struct scsi_disk {int /*<<< orphan*/  dev; int /*<<< orphan*/  device; } ;
struct gendisk {scalar_t__ private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scsi_device_get (int /*<<< orphan*/ ) ; 
 struct scsi_disk* scsi_disk (struct gendisk*) ; 
 int /*<<< orphan*/  sd_ref_mutex ; 

__attribute__((used)) static struct scsi_disk *scsi_disk_get(struct gendisk *disk)
{
	struct scsi_disk *sdkp = NULL;

	mutex_lock(&sd_ref_mutex);

	if (disk->private_data) {
		sdkp = scsi_disk(disk);
		if (scsi_device_get(sdkp->device) == 0)
			get_device(&sdkp->dev);
		else
			sdkp = NULL;
	}
	mutex_unlock(&sd_ref_mutex);
	return sdkp;
}