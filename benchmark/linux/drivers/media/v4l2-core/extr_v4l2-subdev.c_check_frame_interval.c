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
struct v4l2_subdev_frame_interval {int /*<<< orphan*/  pad; } ;
struct v4l2_subdev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int check_pad (struct v4l2_subdev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int check_frame_interval(struct v4l2_subdev *sd,
				       struct v4l2_subdev_frame_interval *fi)
{
	if (!fi)
		return -EINVAL;

	return check_pad(sd, fi->pad);
}