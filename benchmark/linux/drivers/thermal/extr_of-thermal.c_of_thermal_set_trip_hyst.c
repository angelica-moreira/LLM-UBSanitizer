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
struct thermal_zone_device {struct __thermal_zone* devdata; } ;
struct __thermal_zone {int ntrips; TYPE_1__* trips; } ;
struct TYPE_2__ {int hysteresis; } ;

/* Variables and functions */
 int EDOM ; 

__attribute__((used)) static int of_thermal_set_trip_hyst(struct thermal_zone_device *tz, int trip,
				    int hyst)
{
	struct __thermal_zone *data = tz->devdata;

	if (trip >= data->ntrips || trip < 0)
		return -EDOM;

	/* thermal framework should take care of data->mask & (1 << trip) */
	data->trips[trip].hysteresis = hyst;

	return 0;
}