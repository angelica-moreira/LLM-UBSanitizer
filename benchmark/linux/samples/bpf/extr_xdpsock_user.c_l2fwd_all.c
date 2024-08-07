#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct pollfd {int events; int /*<<< orphan*/  fd; } ;
typedef  int /*<<< orphan*/  fds ;
struct TYPE_3__ {int /*<<< orphan*/  xsk; } ;

/* Variables and functions */
 int MAX_SOCKS ; 
 int POLLIN ; 
 int POLLOUT ; 
 int /*<<< orphan*/  l2fwd (TYPE_1__*,struct pollfd*) ; 
 int /*<<< orphan*/  memset (struct pollfd*,int /*<<< orphan*/ ,int) ; 
 int num_socks ; 
 scalar_t__ opt_poll ; 
 int /*<<< orphan*/  opt_timeout ; 
 int poll (struct pollfd*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xsk_socket__fd (int /*<<< orphan*/ ) ; 
 TYPE_1__** xsks ; 

__attribute__((used)) static void l2fwd_all(void)
{
	struct pollfd fds[MAX_SOCKS];
	int i, ret;

	memset(fds, 0, sizeof(fds));

	for (i = 0; i < num_socks; i++) {
		fds[i].fd = xsk_socket__fd(xsks[i]->xsk);
		fds[i].events = POLLOUT | POLLIN;
	}

	for (;;) {
		if (opt_poll) {
			ret = poll(fds, num_socks, opt_timeout);
			if (ret <= 0)
				continue;
		}

		for (i = 0; i < num_socks; i++)
			l2fwd(xsks[i], fds);
	}
}