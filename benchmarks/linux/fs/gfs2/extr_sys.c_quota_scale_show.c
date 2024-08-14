#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int gt_quota_scale_num; int gt_quota_scale_den; } ;
struct gfs2_sbd {TYPE_1__ sd_tune; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int,int) ; 

__attribute__((used)) static ssize_t quota_scale_show(struct gfs2_sbd *sdp, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%u %u\n",
			sdp->sd_tune.gt_quota_scale_num,
			sdp->sd_tune.gt_quota_scale_den);
}