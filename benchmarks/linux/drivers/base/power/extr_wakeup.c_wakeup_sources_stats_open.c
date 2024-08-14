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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int seq_open_private (struct file*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  wakeup_sources_stats_seq_ops ; 

__attribute__((used)) static int wakeup_sources_stats_open(struct inode *inode, struct file *file)
{
	return seq_open_private(file, &wakeup_sources_stats_seq_ops, sizeof(int));
}