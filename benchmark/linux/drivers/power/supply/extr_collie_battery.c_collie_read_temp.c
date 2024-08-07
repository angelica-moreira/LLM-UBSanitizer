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
struct collie_bat {scalar_t__ gpio_temp; unsigned long adc_temp_divider; int /*<<< orphan*/  adc_temp; } ;

/* Variables and functions */
 int /*<<< orphan*/  UCB_SYNC ; 
 int /*<<< orphan*/  bat_lock ; 
 int /*<<< orphan*/  gpio_set_value (scalar_t__,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ucb ; 
 int /*<<< orphan*/  ucb1x00_adc_disable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ucb1x00_adc_enable (int /*<<< orphan*/ ) ; 
 unsigned long ucb1x00_adc_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned long collie_read_temp(struct collie_bat *bat)
{
	unsigned long value = 0;
	if (bat->gpio_temp < 0 || bat->adc_temp < 0)
		return 0;

	mutex_lock(&bat_lock);
	gpio_set_value(bat->gpio_temp, 1);
	msleep(5);
	ucb1x00_adc_enable(ucb);
	value = ucb1x00_adc_read(ucb, bat->adc_temp, UCB_SYNC);
	ucb1x00_adc_disable(ucb);
	gpio_set_value(bat->gpio_temp, 0);
	mutex_unlock(&bat_lock);

	value = value * 10000 / bat->adc_temp_divider;

	return value;
}