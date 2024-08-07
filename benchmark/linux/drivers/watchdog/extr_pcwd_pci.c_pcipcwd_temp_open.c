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
struct TYPE_2__ {int /*<<< orphan*/  supports_temp; } ;

/* Variables and functions */
 int ENODEV ; 
 TYPE_1__ pcipcwd_private ; 
 int stream_open (struct inode*,struct file*) ; 

__attribute__((used)) static int pcipcwd_temp_open(struct inode *inode, struct file *file)
{
	if (!pcipcwd_private.supports_temp)
		return -ENODEV;

	return stream_open(inode, file);
}