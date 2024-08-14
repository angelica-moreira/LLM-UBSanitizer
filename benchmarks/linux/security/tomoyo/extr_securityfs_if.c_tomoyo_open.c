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
typedef  int /*<<< orphan*/  u8 ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct TYPE_2__ {scalar_t__ i_private; } ;

/* Variables and functions */
 TYPE_1__* file_inode (struct file*) ; 
 int tomoyo_open_control (int const,struct file*) ; 

__attribute__((used)) static int tomoyo_open(struct inode *inode, struct file *file)
{
	const int key = ((u8 *) file_inode(file)->i_private)
		- ((u8 *) NULL);
	return tomoyo_open_control(key, file);
}