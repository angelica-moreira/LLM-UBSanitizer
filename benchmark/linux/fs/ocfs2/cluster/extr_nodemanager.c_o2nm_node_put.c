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
struct o2nm_node {int /*<<< orphan*/  nd_item; } ;

/* Variables and functions */
 int /*<<< orphan*/  config_item_put (int /*<<< orphan*/ *) ; 

void o2nm_node_put(struct o2nm_node *node)
{
	config_item_put(&node->nd_item);
}