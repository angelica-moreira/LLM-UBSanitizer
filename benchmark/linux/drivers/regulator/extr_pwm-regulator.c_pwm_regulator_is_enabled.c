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
struct regulator_dev {int dummy; } ;
struct pwm_regulator_data {int /*<<< orphan*/  pwm; scalar_t__ enb_gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiod_get_value_cansleep (scalar_t__) ; 
 int pwm_is_enabled (int /*<<< orphan*/ ) ; 
 struct pwm_regulator_data* rdev_get_drvdata (struct regulator_dev*) ; 

__attribute__((used)) static int pwm_regulator_is_enabled(struct regulator_dev *dev)
{
	struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);

	if (drvdata->enb_gpio && !gpiod_get_value_cansleep(drvdata->enb_gpio))
		return false;

	return pwm_is_enabled(drvdata->pwm);
}