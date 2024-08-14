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
struct __thermal_zone {int /*<<< orphan*/  sensor_data; TYPE_1__* ops; } ;
typedef  enum thermal_trend { ____Placeholder_thermal_trend } thermal_trend ;
struct TYPE_2__ {int (* get_trend ) (int /*<<< orphan*/ ,int,int*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int stub1 (int /*<<< orphan*/ ,int,int*) ; 

__attribute__((used)) static int of_thermal_get_trend(struct thermal_zone_device *tz, int trip,
				enum thermal_trend *trend)
{
	struct __thermal_zone *data = tz->devdata;

	if (!data->ops->get_trend)
		return -EINVAL;

	return data->ops->get_trend(data->sensor_data, trip, trend);
}