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
typedef  int /*<<< orphan*/  line ;

/* Variables and functions */
 int /*<<< orphan*/  O_RDONLY ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int open (char const*,int /*<<< orphan*/ ) ; 
 scalar_t__ read (int,char*,int) ; 

int filename__read_int(const char *filename, int *value)
{
	char line[64];
	int fd = open(filename, O_RDONLY), err = -1;

	if (fd < 0)
		return -1;

	if (read(fd, line, sizeof(line)) > 0) {
		*value = atoi(line);
		err = 0;
	}

	close(fd);
	return err;
}