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
struct v4l2_subdev {int dummy; } ;
struct tuner {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  V4L2_TUNER_RADIO ; 
 int /*<<< orphan*/  set_freq (struct tuner*,int /*<<< orphan*/ ) ; 
 scalar_t__ set_mode (struct tuner*,int /*<<< orphan*/ ) ; 
 struct tuner* to_tuner (struct v4l2_subdev*) ; 

__attribute__((used)) static int tuner_s_radio(struct v4l2_subdev *sd)
{
	struct tuner *t = to_tuner(sd);

	if (set_mode(t, V4L2_TUNER_RADIO) == 0)
		set_freq(t, 0);
	return 0;
}