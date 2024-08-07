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

/* Variables and functions */
 struct fwnode_handle* fwnode_call_ptr_op (struct fwnode_handle const*,int /*<<< orphan*/ ,struct fwnode_handle*) ; 
 int /*<<< orphan*/  graph_get_next_endpoint ; 

struct fwnode_handle *
fwnode_graph_get_next_endpoint(const struct fwnode_handle *fwnode,
			       struct fwnode_handle *prev)
{
	return fwnode_call_ptr_op(fwnode, graph_get_next_endpoint, prev);
}