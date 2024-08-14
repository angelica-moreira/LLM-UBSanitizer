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
typedef  int umode_t ;
typedef  int u32 ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int hwmon_temp ; 
#define  hwmon_temp_input 130 
#define  hwmon_temp_max 129 
#define  hwmon_temp_max_hyst 128 

__attribute__((used)) static umode_t tmp102_is_visible(const void *data, enum hwmon_sensor_types type,
				 u32 attr, int channel)
{
	if (type != hwmon_temp)
		return 0;

	switch (attr) {
	case hwmon_temp_input:
		return 0444;
	case hwmon_temp_max_hyst:
	case hwmon_temp_max:
		return 0644;
	default:
		return 0;
	}
}