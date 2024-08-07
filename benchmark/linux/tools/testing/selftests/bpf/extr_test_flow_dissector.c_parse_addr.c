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
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  error (int,int /*<<< orphan*/ ,char*) ; 
 int inet_pton (int,char const*,void*) ; 

__attribute__((used)) static void parse_addr(int family, void *addr, const char *optarg)
{
	int ret;

	ret = inet_pton(family, optarg, addr);
	if (ret == -1)
		error(1, errno, "inet_pton");
	if (ret == 0)
		error(1, 0, "inet_pton: bad string");
}