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
struct fs_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct fs_node*) ; 

__attribute__((used)) static void del_sw_prio(struct fs_node *node)
{
	kfree(node);
}