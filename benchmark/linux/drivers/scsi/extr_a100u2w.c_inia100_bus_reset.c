#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct scsi_cmnd {TYPE_2__* device; } ;
struct orc_host {int dummy; } ;
struct TYPE_4__ {TYPE_1__* host; } ;
struct TYPE_3__ {scalar_t__ hostdata; } ;

/* Variables and functions */
 int orc_reset_scsi_bus (struct orc_host*) ; 

__attribute__((used)) static int inia100_bus_reset(struct scsi_cmnd * cmd)
{				/* I need Host Control Block Information */
	struct orc_host *host;
	host = (struct orc_host *) cmd->device->host->hostdata;
	return orc_reset_scsi_bus(host);
}