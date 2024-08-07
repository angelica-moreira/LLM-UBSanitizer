#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {unsigned int max_port_number; } ;
struct tb_switch {scalar_t__ is_unplugged; struct tb_port* ports; TYPE_2__ config; } ;
struct tb_port {TYPE_1__* remote; TYPE_3__* xdomain; } ;
struct TYPE_6__ {scalar_t__ is_unplugged; } ;
struct TYPE_4__ {struct tb_switch* sw; } ;

/* Variables and functions */
 int /*<<< orphan*/  remove_unplugged_switch (struct tb_switch*) ; 
 scalar_t__ tb_port_has_remote (struct tb_port*) ; 
 int /*<<< orphan*/  tb_xdomain_remove (TYPE_3__*) ; 

__attribute__((used)) static void icm_free_unplugged_children(struct tb_switch *sw)
{
	unsigned int i;

	for (i = 1; i <= sw->config.max_port_number; i++) {
		struct tb_port *port = &sw->ports[i];

		if (port->xdomain && port->xdomain->is_unplugged) {
			tb_xdomain_remove(port->xdomain);
			port->xdomain = NULL;
		} else if (tb_port_has_remote(port)) {
			if (port->remote->sw->is_unplugged) {
				remove_unplugged_switch(port->remote->sw);
				port->remote = NULL;
			} else {
				icm_free_unplugged_children(port->remote->sw);
			}
		}
	}
}