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
typedef  int /*<<< orphan*/  u8 ;
struct hfs_bnode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hfs_bnode_read (struct hfs_bnode*,int /*<<< orphan*/ *,int,int) ; 

u8 hfs_bnode_read_u8(struct hfs_bnode *node, int off)
{
	u8 data;
	/* TODO: optimize later... */
	hfs_bnode_read(node, &data, off, 1);
	return data;
}