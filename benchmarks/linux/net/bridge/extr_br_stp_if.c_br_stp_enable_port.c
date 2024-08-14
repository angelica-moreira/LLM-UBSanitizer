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
struct net_bridge_port {int /*<<< orphan*/  br; } ;

/* Variables and functions */
 int /*<<< orphan*/  RTM_NEWLINK ; 
 int /*<<< orphan*/  br_ifinfo_notify (int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct net_bridge_port*) ; 
 int /*<<< orphan*/  br_init_port (struct net_bridge_port*) ; 
 int /*<<< orphan*/  br_port_state_selection (int /*<<< orphan*/ ) ; 

void br_stp_enable_port(struct net_bridge_port *p)
{
	br_init_port(p);
	br_port_state_selection(p->br);
	br_ifinfo_notify(RTM_NEWLINK, NULL, p);
}