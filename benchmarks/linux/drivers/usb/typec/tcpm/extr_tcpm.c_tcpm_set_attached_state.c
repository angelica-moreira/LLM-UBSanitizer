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
struct tcpm_port {int /*<<< orphan*/  data_role; int /*<<< orphan*/  pwr_role; TYPE_1__* tcpc; } ;
struct TYPE_2__ {int (* set_roles ) (TYPE_1__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (TYPE_1__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tcpm_set_attached_state(struct tcpm_port *port, bool attached)
{
	return port->tcpc->set_roles(port->tcpc, attached, port->pwr_role,
				     port->data_role);
}