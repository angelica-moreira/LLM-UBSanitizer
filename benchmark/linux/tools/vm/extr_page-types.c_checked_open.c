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
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int open (char const*,int) ; 
 int /*<<< orphan*/  perror (char const*) ; 

__attribute__((used)) static int checked_open(const char *pathname, int flags)
{
	int fd = open(pathname, flags);

	if (fd < 0) {
		perror(pathname);
		exit(EXIT_FAILURE);
	}

	return fd;
}