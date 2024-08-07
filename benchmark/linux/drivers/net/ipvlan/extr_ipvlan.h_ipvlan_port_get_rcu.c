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
struct net_device {int /*<<< orphan*/  rx_handler_data; } ;
struct ipvl_port {int dummy; } ;

/* Variables and functions */
 struct ipvl_port* rcu_dereference (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct ipvl_port *ipvlan_port_get_rcu(const struct net_device *d)
{
	return rcu_dereference(d->rx_handler_data);
}