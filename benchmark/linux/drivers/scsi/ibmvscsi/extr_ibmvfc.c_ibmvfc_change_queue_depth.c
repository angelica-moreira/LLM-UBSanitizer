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
struct scsi_device {int dummy; } ;

/* Variables and functions */
 int IBMVFC_MAX_CMDS_PER_LUN ; 
 int scsi_change_queue_depth (struct scsi_device*,int) ; 

__attribute__((used)) static int ibmvfc_change_queue_depth(struct scsi_device *sdev, int qdepth)
{
	if (qdepth > IBMVFC_MAX_CMDS_PER_LUN)
		qdepth = IBMVFC_MAX_CMDS_PER_LUN;

	return scsi_change_queue_depth(sdev, qdepth);
}