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
struct zfcp_scsi_dev {int dummy; } ;
struct scsi_device {int dummy; } ;

/* Variables and functions */
 struct zfcp_scsi_dev* scsi_transport_device_data (struct scsi_device*) ; 

__attribute__((used)) static inline struct zfcp_scsi_dev *sdev_to_zfcp(struct scsi_device *sdev)
{
	return scsi_transport_device_data(sdev);
}