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
typedef  void DIR ;

/* Variables and functions */
 int errno ; 
 void* opendir (char*) ; 

void *open_dir(char *path, int *err_out)
{
	DIR *dir;

	dir = opendir(path);
	*err_out = errno;

	return dir;
}