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
struct thermal_zone_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int fanoff ; 
 int fanon ; 

__attribute__((used)) static int acerhdf_get_trip_hyst(struct thermal_zone_device *thermal, int trip,
				 int *temp)
{
	if (trip != 0)
		return -EINVAL;

	*temp = fanon - fanoff;

	return 0;
}