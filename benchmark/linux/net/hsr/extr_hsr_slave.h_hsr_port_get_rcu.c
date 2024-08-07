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
struct hsr_port {int dummy; } ;

/* Variables and functions */
 scalar_t__ hsr_port_exists (struct net_device const*) ; 
 struct hsr_port* rcu_dereference (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct hsr_port *hsr_port_get_rcu(const struct net_device *dev)
{
	return hsr_port_exists(dev) ?
				rcu_dereference(dev->rx_handler_data) : NULL;
}