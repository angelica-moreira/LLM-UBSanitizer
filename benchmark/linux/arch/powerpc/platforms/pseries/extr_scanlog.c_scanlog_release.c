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
 unsigned int* scanlog_buffer ; 

__attribute__((used)) static int scanlog_release(struct inode * inode, struct file * file)
{
	unsigned int *data = scanlog_buffer;

	data[0] = 0;
	return 0;
}