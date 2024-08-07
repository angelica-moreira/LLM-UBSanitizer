#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct ocfs2_cluster_connection {int dummy; } ;
struct TYPE_4__ {TYPE_1__* sp_ops; } ;
struct TYPE_3__ {int (* this_node ) (struct ocfs2_cluster_connection*,unsigned int*) ;} ;

/* Variables and functions */
 TYPE_2__* active_stack ; 
 int stub1 (struct ocfs2_cluster_connection*,unsigned int*) ; 

int ocfs2_cluster_this_node(struct ocfs2_cluster_connection *conn,
			    unsigned int *node)
{
	return active_stack->sp_ops->this_node(conn, node);
}