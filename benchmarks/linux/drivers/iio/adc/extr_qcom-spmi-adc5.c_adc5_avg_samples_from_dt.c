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

/* Variables and functions */
 scalar_t__ ADC5_AVG_SAMPLES_MAX ; 
 int EINVAL ; 
 int __ffs (scalar_t__) ; 
 int /*<<< orphan*/  is_power_of_2 (scalar_t__) ; 

__attribute__((used)) static int adc5_avg_samples_from_dt(u32 value)
{
	if (!is_power_of_2(value) || value > ADC5_AVG_SAMPLES_MAX)
		return -EINVAL;

	return __ffs(value);
}