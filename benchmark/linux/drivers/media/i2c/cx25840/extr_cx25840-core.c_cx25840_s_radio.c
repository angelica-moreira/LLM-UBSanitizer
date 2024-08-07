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
struct cx25840_state {int radio; } ;

/* Variables and functions */
 struct cx25840_state* to_state (struct v4l2_subdev*) ; 

__attribute__((used)) static int cx25840_s_radio(struct v4l2_subdev *sd)
{
	struct cx25840_state *state = to_state(sd);

	state->radio = 1;
	return 0;
}