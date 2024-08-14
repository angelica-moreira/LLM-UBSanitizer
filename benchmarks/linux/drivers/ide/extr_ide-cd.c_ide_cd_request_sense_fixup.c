#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct request {int /*<<< orphan*/ * cmd; } ;
struct ide_cmd {int nleft; struct request* rq; } ;
typedef  int /*<<< orphan*/  ide_drive_t ;
struct TYPE_2__ {scalar_t__* cmd; } ;

/* Variables and functions */
 scalar_t__ GPCMD_REQUEST_SENSE ; 
 int /*<<< orphan*/  IDE_DBG_FUNC ; 
 int /*<<< orphan*/  ide_debug_log (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 TYPE_1__* scsi_req (struct request*) ; 

__attribute__((used)) static void ide_cd_request_sense_fixup(ide_drive_t *drive, struct ide_cmd *cmd)
{
	struct request *rq = cmd->rq;

	ide_debug_log(IDE_DBG_FUNC, "rq->cmd[0]: 0x%x", rq->cmd[0]);

	/*
	 * Some of the trailing request sense fields are optional,
	 * and some drives don't send them.  Sigh.
	 */
	if (scsi_req(rq)->cmd[0] == GPCMD_REQUEST_SENSE &&
	    cmd->nleft > 0 && cmd->nleft <= 5)
		cmd->nleft = 0;
}