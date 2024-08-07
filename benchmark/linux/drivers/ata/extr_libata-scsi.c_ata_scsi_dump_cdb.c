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
struct scsi_device {int /*<<< orphan*/  lun; int /*<<< orphan*/  id; int /*<<< orphan*/  channel; } ;
struct scsi_cmnd {int /*<<< orphan*/  cmnd; struct scsi_device* device; } ;
struct ata_port {int /*<<< orphan*/  print_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  VPRINTK (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ata_scsi_dump_cdb(struct ata_port *ap,
				     struct scsi_cmnd *cmd)
{
#ifdef ATA_VERBOSE_DEBUG
	struct scsi_device *scsidev = cmd->device;

	VPRINTK("CDB (%u:%d,%d,%lld) %9ph\n",
		ap->print_id,
		scsidev->channel, scsidev->id, scsidev->lun,
		cmd->cmnd);
#endif
}