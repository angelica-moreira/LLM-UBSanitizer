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
struct scsi_cmnd {struct scsi_device* device; } ;
struct ahc_softc {int dummy; } ;
struct ahc_devinfo {int /*<<< orphan*/  lun; int /*<<< orphan*/  target; int /*<<< orphan*/  channel; } ;
typedef  int /*<<< orphan*/  ahc_queue_alg ;

/* Variables and functions */
 int /*<<< orphan*/  AC_TRANSFER_NEG ; 
 int /*<<< orphan*/  ahc_platform_set_tags (struct ahc_softc*,struct scsi_device*,struct ahc_devinfo*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ahc_send_async (struct ahc_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ahc_set_tags(struct ahc_softc *ahc, struct scsi_cmnd *cmd,
	     struct ahc_devinfo *devinfo, ahc_queue_alg alg)
{
	struct scsi_device *sdev = cmd->device;

 	ahc_platform_set_tags(ahc, sdev, devinfo, alg);
 	ahc_send_async(ahc, devinfo->channel, devinfo->target,
 		       devinfo->lun, AC_TRANSFER_NEG);
}