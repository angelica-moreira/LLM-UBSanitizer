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
struct scsi_device {int /*<<< orphan*/  sdev_gendev; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ONCE (int,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ *) ; 
 int scsi_internal_device_block (struct scsi_device*) ; 

__attribute__((used)) static void
device_block(struct scsi_device *sdev, void *data)
{
	int ret;

	ret = scsi_internal_device_block(sdev);

	WARN_ONCE(ret, "scsi_internal_device_block(%s) failed: ret = %d\n",
		  dev_name(&sdev->sdev_gendev), ret);
}