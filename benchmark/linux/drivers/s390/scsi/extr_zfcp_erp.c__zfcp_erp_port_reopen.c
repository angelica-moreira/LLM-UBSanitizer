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
struct zfcp_port {int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  ZFCP_ERP_ACTION_REOPEN_PORT ; 
 int /*<<< orphan*/  zfcp_erp_action_enqueue (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct zfcp_port*,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zfcp_erp_port_block (struct zfcp_port*,int) ; 
 int /*<<< orphan*/  zfcp_scsi_schedule_rport_block (struct zfcp_port*) ; 

__attribute__((used)) static void _zfcp_erp_port_reopen(struct zfcp_port *port, int clear,
				  char *dbftag)
{
	zfcp_erp_port_block(port, clear);
	zfcp_scsi_schedule_rport_block(port);

	zfcp_erp_action_enqueue(ZFCP_ERP_ACTION_REOPEN_PORT,
				port->adapter, port, NULL, dbftag, 0);
}