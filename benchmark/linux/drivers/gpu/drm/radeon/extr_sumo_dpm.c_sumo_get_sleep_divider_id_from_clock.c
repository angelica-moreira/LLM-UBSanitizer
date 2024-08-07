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
typedef  scalar_t__ u32 ;
struct sumo_power_info {int /*<<< orphan*/  enable_sclk_ds; } ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ SUMO_MAX_DEEPSLEEP_DIVIDER_ID ; 
 scalar_t__ SUMO_MINIMUM_ENGINE_CLOCK ; 
 struct sumo_power_info* sumo_get_pi (struct radeon_device*) ; 
 scalar_t__ sumo_get_sleep_divider_from_id (scalar_t__) ; 

u32 sumo_get_sleep_divider_id_from_clock(struct radeon_device *rdev,
					 u32 sclk,
					 u32 min_sclk_in_sr)
{
	struct sumo_power_info *pi = sumo_get_pi(rdev);
	u32 i;
	u32 temp;
	u32 min = (min_sclk_in_sr > SUMO_MINIMUM_ENGINE_CLOCK) ?
		min_sclk_in_sr : SUMO_MINIMUM_ENGINE_CLOCK;

	if (sclk < min)
		return 0;

	if (!pi->enable_sclk_ds)
		return 0;

	for (i = SUMO_MAX_DEEPSLEEP_DIVIDER_ID;  ; i--) {
		temp = sclk / sumo_get_sleep_divider_from_id(i);

		if (temp >= min || i == 0)
			break;
	}
	return i;
}