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
struct gfs2_sbd {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EINVAL ; 
 int EPERM ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gfs2_lm_withdraw (struct gfs2_sbd*,char*) ; 
 int kstrtoint (char const*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static ssize_t withdraw_store(struct gfs2_sbd *sdp, const char *buf, size_t len)
{
	int error, val;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	error = kstrtoint(buf, 0, &val);
	if (error)
		return error;

	if (val != 1)
		return -EINVAL;

	gfs2_lm_withdraw(sdp, "withdrawing from cluster at user's request\n");

	return len;
}