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
struct net_bridge {int /*<<< orphan*/  topology_change_timer; int /*<<< orphan*/  tcn_timer; int /*<<< orphan*/  hello_timer; } ;

/* Variables and functions */
 int /*<<< orphan*/  br_hello_timer_expired ; 
 int /*<<< orphan*/  br_tcn_timer_expired ; 
 int /*<<< orphan*/  br_topology_change_timer_expired ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void br_stp_timer_init(struct net_bridge *br)
{
	timer_setup(&br->hello_timer, br_hello_timer_expired, 0);
	timer_setup(&br->tcn_timer, br_tcn_timer_expired, 0);
	timer_setup(&br->topology_change_timer,
		    br_topology_change_timer_expired, 0);
}