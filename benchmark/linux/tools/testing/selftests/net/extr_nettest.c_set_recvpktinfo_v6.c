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
typedef  int /*<<< orphan*/  one ;

/* Variables and functions */
 int ENOTSUP ; 
 int /*<<< orphan*/  IPV6_RECVPKTINFO ; 
 int /*<<< orphan*/  SOL_IPV6 ; 
 int /*<<< orphan*/  log_err_errno (char*) ; 
 int setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 

__attribute__((used)) static int set_recvpktinfo_v6(int sd)
{
	int one = 1;
	int rc;

	rc = setsockopt(sd, SOL_IPV6, IPV6_RECVPKTINFO, &one, sizeof(one));
	if (rc < 0 && rc != -ENOTSUP)
		log_err_errno("setsockopt(IPV6_RECVPKTINFO)");

	return rc;
}