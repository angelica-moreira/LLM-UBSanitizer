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
struct net_device {int dummy; } ;
struct net_bridge_port {int priority; int port_no; int flags; int /*<<< orphan*/  path_cost; struct net_device* dev; struct net_bridge* br; } ;
struct net_bridge {int dummy; } ;

/* Variables and functions */
 int BR_BCAST_FLOOD ; 
 int BR_FLOOD ; 
 int BR_LEARNING ; 
 int BR_MCAST_FLOOD ; 
 int BR_PORT_BITS ; 
 int /*<<< orphan*/  BR_STATE_DISABLED ; 
 int ENOMEM ; 
 struct net_bridge_port* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  br_init_port (struct net_bridge_port*) ; 
 int br_multicast_add_port (struct net_bridge_port*) ; 
 int /*<<< orphan*/  br_set_state (struct net_bridge_port*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  br_stp_port_timer_init (struct net_bridge_port*) ; 
 int /*<<< orphan*/  dev_hold (struct net_device*) ; 
 int /*<<< orphan*/  dev_put (struct net_device*) ; 
 int find_portno (struct net_bridge*) ; 
 int /*<<< orphan*/  kfree (struct net_bridge_port*) ; 
 struct net_bridge_port* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  port_cost (struct net_device*) ; 

__attribute__((used)) static struct net_bridge_port *new_nbp(struct net_bridge *br,
				       struct net_device *dev)
{
	struct net_bridge_port *p;
	int index, err;

	index = find_portno(br);
	if (index < 0)
		return ERR_PTR(index);

	p = kzalloc(sizeof(*p), GFP_KERNEL);
	if (p == NULL)
		return ERR_PTR(-ENOMEM);

	p->br = br;
	dev_hold(dev);
	p->dev = dev;
	p->path_cost = port_cost(dev);
	p->priority = 0x8000 >> BR_PORT_BITS;
	p->port_no = index;
	p->flags = BR_LEARNING | BR_FLOOD | BR_MCAST_FLOOD | BR_BCAST_FLOOD;
	br_init_port(p);
	br_set_state(p, BR_STATE_DISABLED);
	br_stp_port_timer_init(p);
	err = br_multicast_add_port(p);
	if (err) {
		dev_put(dev);
		kfree(p);
		p = ERR_PTR(err);
	}

	return p;
}