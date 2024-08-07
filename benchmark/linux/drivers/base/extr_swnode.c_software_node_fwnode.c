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
struct fwnode_handle {int dummy; } ;
struct swnode {struct fwnode_handle fwnode; } ;
struct software_node {int dummy; } ;

/* Variables and functions */
 struct swnode* software_node_to_swnode (struct software_node const*) ; 

struct fwnode_handle *software_node_fwnode(const struct software_node *node)
{
	struct swnode *swnode = software_node_to_swnode(node);

	return swnode ? &swnode->fwnode : NULL;
}