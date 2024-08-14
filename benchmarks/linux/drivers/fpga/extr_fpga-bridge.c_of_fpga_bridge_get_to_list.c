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
struct list_head {int dummy; } ;
struct fpga_image_info {int dummy; } ;
struct fpga_bridge {int /*<<< orphan*/  node; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct fpga_bridge*) ; 
 int PTR_ERR (struct fpga_bridge*) ; 
 int /*<<< orphan*/  bridge_list_lock ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,struct list_head*) ; 
 struct fpga_bridge* of_fpga_bridge_get (struct device_node*,struct fpga_image_info*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int of_fpga_bridge_get_to_list(struct device_node *np,
			       struct fpga_image_info *info,
			       struct list_head *bridge_list)
{
	struct fpga_bridge *bridge;
	unsigned long flags;

	bridge = of_fpga_bridge_get(np, info);
	if (IS_ERR(bridge))
		return PTR_ERR(bridge);

	spin_lock_irqsave(&bridge_list_lock, flags);
	list_add(&bridge->node, bridge_list);
	spin_unlock_irqrestore(&bridge_list_lock, flags);

	return 0;
}