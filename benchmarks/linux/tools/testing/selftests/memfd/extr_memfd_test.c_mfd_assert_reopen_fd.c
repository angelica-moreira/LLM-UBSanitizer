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
 int /*<<< orphan*/  O_RDWR ; 
 int /*<<< orphan*/  abort () ; 
 int open (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static int mfd_assert_reopen_fd(int fd_in)
{
	int r, fd;
	char path[100];

	sprintf(path, "/proc/self/fd/%d", fd_in);

	fd = open(path, O_RDWR);
	if (fd < 0) {
		printf("re-open of existing fd %d failed\n", fd_in);
		abort();
	}

	return fd;
}