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
struct file {int /*<<< orphan*/  private_data; } ;

/* Variables and functions */
 int stream_open (struct inode*,struct file*) ; 

__attribute__((used)) static int cros_ec_console_log_open(struct inode *inode, struct file *file)
{
	file->private_data = inode->i_private;

	return stream_open(inode, file);
}