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
typedef  struct rb_node {struct rb_node const* rb_right; struct rb_node const* rb_left; } const rb_node ;

/* Variables and functions */
 scalar_t__ RB_EMPTY_NODE (struct rb_node const*) ; 
 struct rb_node const* rb_parent (struct rb_node const*) ; 

struct rb_node *rb_next(const struct rb_node *node)
{
	struct rb_node *parent;

	if (RB_EMPTY_NODE(node))
		return NULL;

	/*
	 * If we have a right-hand child, go down and then left as far
	 * as we can.
	 */
	if (node->rb_right) {
		node = node->rb_right;
		while (node->rb_left)
			node=node->rb_left;
		return (struct rb_node *)node;
	}

	/*
	 * No right-hand children. Everything down and left is smaller than us,
	 * so any 'next' node must be in the general direction of our parent.
	 * Go up the tree; any time the ancestor is a right-hand child of its
	 * parent, keep going up. First time it's a left-hand child of its
	 * parent, said parent is our 'next' node.
	 */
	while ((parent = rb_parent(node)) && node == parent->rb_right)
		node = parent;

	return parent;
}