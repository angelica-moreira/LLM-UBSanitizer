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
 int /*<<< orphan*/  SENDMSG6_PROG_PATH ; 
 int load_path (struct sock_addr_test const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int sendmsg6_rw_c_prog_load(const struct sock_addr_test *test)
{
	return load_path(test, SENDMSG6_PROG_PATH);
}