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
 int O_CREAT ; 
 int O_RDWR ; 
 int errno ; 
 int open64 (char*,int,int) ; 

int file_create(char *name, int mode)
{
	int fd;

	fd = open64(name, O_CREAT | O_RDWR, mode);
	if (fd < 0)
		return -errno;
	return fd;
}