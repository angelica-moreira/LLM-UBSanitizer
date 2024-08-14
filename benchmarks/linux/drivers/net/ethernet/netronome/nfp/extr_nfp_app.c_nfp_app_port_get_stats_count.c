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
struct nfp_port {TYPE_2__* app; } ;
struct TYPE_4__ {TYPE_1__* type; } ;
struct TYPE_3__ {int (* port_get_stats_count ) (TYPE_2__*,struct nfp_port*) ;} ;

/* Variables and functions */
 int stub1 (TYPE_2__*,struct nfp_port*) ; 

int nfp_app_port_get_stats_count(struct nfp_port *port)
{
	if (!port || !port->app || !port->app->type->port_get_stats_count)
		return 0;
	return port->app->type->port_get_stats_count(port->app, port);
}