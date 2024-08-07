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

/* Variables and functions */
 int errno ; 
 int mknod (char const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  os_makedev (unsigned int,unsigned int) ; 

int do_mknod(const char *file, int mode, unsigned int major, unsigned int minor)
{
	int err;

	err = mknod(file, mode, os_makedev(major, minor));
	if (err)
		return -errno;
	return 0;
}