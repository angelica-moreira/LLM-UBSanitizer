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
struct zfcp_port {struct zfcp_adapter* adapter; } ;
struct zfcp_adapter {int /*<<< orphan*/  erp_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  _zfcp_erp_port_forced_reopen (struct zfcp_port*,int,char*) ; 
 int /*<<< orphan*/  write_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  write_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void zfcp_erp_port_forced_reopen(struct zfcp_port *port, int clear,
				 char *dbftag)
{
	unsigned long flags;
	struct zfcp_adapter *adapter = port->adapter;

	write_lock_irqsave(&adapter->erp_lock, flags);
	_zfcp_erp_port_forced_reopen(port, clear, dbftag);
	write_unlock_irqrestore(&adapter->erp_lock, flags);
}