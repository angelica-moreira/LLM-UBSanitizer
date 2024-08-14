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
struct scsi_device {struct hpsa_scsi_dev_t* hostdata; } ;
struct hpsa_scsi_dev_t {int was_removed; } ;

/* Variables and functions */

__attribute__((used)) static void hpsa_slave_destroy(struct scsi_device *sdev)
{
	struct hpsa_scsi_dev_t *hdev = NULL;

	hdev = sdev->hostdata;

	if (hdev)
		hdev->was_removed = 1;
}