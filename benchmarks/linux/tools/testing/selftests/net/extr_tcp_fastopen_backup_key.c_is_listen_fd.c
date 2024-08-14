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
 int N_LISTEN ; 
 int* rcv_fds ; 

__attribute__((used)) static bool is_listen_fd(int fd)
{
	int i;

	for (i = 0; i < N_LISTEN; i++) {
		if (rcv_fds[i] == fd)
			return true;
	}
	return false;
}