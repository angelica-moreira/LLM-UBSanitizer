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
struct gelic_wl_info {int dummy; } ;
struct gelic_port {int dummy; } ;

/* Variables and functions */
 struct gelic_wl_info* port_priv (struct gelic_port*) ; 

__attribute__((used)) static inline struct gelic_wl_info *port_wl(struct gelic_port *port)
{
	return port_priv(port);
}