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
struct ltv350qv {int dummy; } ;
struct lcd_device {int dummy; } ;

/* Variables and functions */
 struct ltv350qv* lcd_get_data (struct lcd_device*) ; 
 int ltv350qv_power (struct ltv350qv*,int) ; 

__attribute__((used)) static int ltv350qv_set_power(struct lcd_device *ld, int power)
{
	struct ltv350qv *lcd = lcd_get_data(ld);

	return ltv350qv_power(lcd, power);
}