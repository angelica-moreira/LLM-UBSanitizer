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
struct rocker_world_ops {int (* port_init ) (struct rocker_port*) ;} ;
struct rocker_port {TYPE_1__* rocker; } ;
struct TYPE_2__ {struct rocker_world_ops* wops; } ;

/* Variables and functions */
 int stub1 (struct rocker_port*) ; 

__attribute__((used)) static int rocker_world_port_init(struct rocker_port *rocker_port)
{
	struct rocker_world_ops *wops = rocker_port->rocker->wops;

	if (!wops->port_init)
		return 0;
	return wops->port_init(rocker_port);
}