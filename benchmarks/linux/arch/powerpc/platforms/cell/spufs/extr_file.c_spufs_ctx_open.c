#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  i_ctx; } ;

/* Variables and functions */
 TYPE_1__* SPUFS_I (struct inode*) ; 
 int single_open (struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spufs_show_ctx ; 

__attribute__((used)) static int spufs_ctx_open(struct inode *inode, struct file *file)
{
	return single_open(file, spufs_show_ctx, SPUFS_I(inode)->i_ctx);
}