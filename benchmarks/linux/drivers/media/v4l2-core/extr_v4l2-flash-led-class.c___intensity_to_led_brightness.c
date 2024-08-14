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
typedef  int u32 ;
struct v4l2_ctrl {scalar_t__ minimum; scalar_t__ step; } ;
typedef  int s32 ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */

__attribute__((used)) static enum led_brightness __intensity_to_led_brightness(
					struct v4l2_ctrl *ctrl, s32 intensity)
{
	intensity -= ctrl->minimum;
	intensity /= (u32) ctrl->step;

	/*
	 * Indicator LEDs, unlike torch LEDs, are turned on/off basing on
	 * the state of V4L2_CID_FLASH_INDICATOR_INTENSITY control only.
	 * Therefore it must be possible to set it to 0 level which in
	 * the LED subsystem reflects LED_OFF state.
	 */
	if (ctrl->minimum)
		++intensity;

	return intensity;
}