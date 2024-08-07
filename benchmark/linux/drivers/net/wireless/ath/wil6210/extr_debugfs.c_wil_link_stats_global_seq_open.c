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
struct inode {int /*<<< orphan*/  i_private; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int single_open (struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wil_link_stats_global_debugfs_show ; 

__attribute__((used)) static int
wil_link_stats_global_seq_open(struct inode *inode, struct file *file)
{
	return single_open(file, wil_link_stats_global_debugfs_show,
			   inode->i_private);
}