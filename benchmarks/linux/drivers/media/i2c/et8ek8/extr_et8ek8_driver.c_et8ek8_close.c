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
struct v4l2_subdev_fh {int dummy; } ;
struct v4l2_subdev {int dummy; } ;

/* Variables and functions */
 int et8ek8_set_power (struct v4l2_subdev*,int) ; 

__attribute__((used)) static int et8ek8_close(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
	return et8ek8_set_power(sd, false);
}