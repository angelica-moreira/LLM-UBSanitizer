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
struct fcoe_port {struct fcoe_interface* priv; } ;
struct fcoe_interface {int /*<<< orphan*/  list; } ;
struct fc_lport {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fcoe_hostlist ; 
 struct fcoe_interface* fcoe_hostlist_lookup_port (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fcoe_netdev (struct fc_lport const*) ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct fcoe_port* lport_priv (struct fc_lport const*) ; 

__attribute__((used)) static int fcoe_hostlist_add(const struct fc_lport *lport)
{
	struct fcoe_interface *fcoe;
	struct fcoe_port *port;

	fcoe = fcoe_hostlist_lookup_port(fcoe_netdev(lport));
	if (!fcoe) {
		port = lport_priv(lport);
		fcoe = port->priv;
		list_add_tail(&fcoe->list, &fcoe_hostlist);
	}
	return 0;
}