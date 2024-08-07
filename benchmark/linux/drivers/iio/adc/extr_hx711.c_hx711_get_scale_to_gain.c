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
struct TYPE_2__ {int scale; int gain; } ;

/* Variables and functions */
 int EINVAL ; 
 int HX711_GAIN_MAX ; 
 TYPE_1__* hx711_gain_to_scale ; 

__attribute__((used)) static int hx711_get_scale_to_gain(int scale)
{
	int i;

	for (i = 0; i < HX711_GAIN_MAX; i++)
		if (hx711_gain_to_scale[i].scale == scale)
			return hx711_gain_to_scale[i].gain;
	return -EINVAL;
}