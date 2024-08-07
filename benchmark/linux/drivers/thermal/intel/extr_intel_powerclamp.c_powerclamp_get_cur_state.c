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
struct thermal_cooling_device {int dummy; } ;

/* Variables and functions */
 int clamping ; 
 unsigned long pkg_cstate_ratio_cur ; 

__attribute__((used)) static int powerclamp_get_cur_state(struct thermal_cooling_device *cdev,
				 unsigned long *state)
{
	if (true == clamping)
		*state = pkg_cstate_ratio_cur;
	else
		/* to save power, do not poll idle ratio while not clamping */
		*state = -1; /* indicates invalid state */

	return 0;
}