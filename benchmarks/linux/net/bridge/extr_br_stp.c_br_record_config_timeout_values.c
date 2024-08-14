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
struct net_bridge {int /*<<< orphan*/  forward_delay; int /*<<< orphan*/  hello_time; int /*<<< orphan*/  max_age; } ;
struct br_config_bpdu {int /*<<< orphan*/  topology_change; int /*<<< orphan*/  forward_delay; int /*<<< orphan*/  hello_time; int /*<<< orphan*/  max_age; } ;

/* Variables and functions */
 int /*<<< orphan*/  __br_set_topology_change (struct net_bridge*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void br_record_config_timeout_values(struct net_bridge *br,
					    const struct br_config_bpdu *bpdu)
{
	br->max_age = bpdu->max_age;
	br->hello_time = bpdu->hello_time;
	br->forward_delay = bpdu->forward_delay;
	__br_set_topology_change(br, bpdu->topology_change);
}