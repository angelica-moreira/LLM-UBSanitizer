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
struct sock_addr_test {int dummy; } ;

/* Variables and functions */
 int xmsg_ret_only_prog_load (struct sock_addr_test const*,int) ; 

__attribute__((used)) static int sendmsg_allow_prog_load(const struct sock_addr_test *test)
{
	return xmsg_ret_only_prog_load(test, /*rc*/ 1);
}