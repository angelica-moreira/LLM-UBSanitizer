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
struct ata_queued_cmd {int flags; struct ata_port* ap; } ;
struct ata_port {int dummy; } ;

/* Variables and functions */
 int ATA_QCFLAG_FAILED ; 
 int /*<<< orphan*/  ata_eh_freeze_port (struct ata_port*) ; 
 scalar_t__ sil24_init_port (struct ata_port*) ; 

__attribute__((used)) static void sil24_post_internal_cmd(struct ata_queued_cmd *qc)
{
	struct ata_port *ap = qc->ap;

	/* make DMA engine forget about the failed command */
	if ((qc->flags & ATA_QCFLAG_FAILED) && sil24_init_port(ap))
		ata_eh_freeze_port(ap);
}