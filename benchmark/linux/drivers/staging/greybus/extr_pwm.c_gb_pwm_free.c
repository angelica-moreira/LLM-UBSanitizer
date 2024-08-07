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
struct pwm_device {int /*<<< orphan*/  hwpwm; } ;
struct pwm_chip {int /*<<< orphan*/  dev; } ;
struct gb_pwm_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gb_pwm_deactivate_operation (struct gb_pwm_chip*,int /*<<< orphan*/ ) ; 
 struct gb_pwm_chip* pwm_chip_to_gb_pwm_chip (struct pwm_chip*) ; 
 scalar_t__ pwm_is_enabled (struct pwm_device*) ; 

__attribute__((used)) static void gb_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	if (pwm_is_enabled(pwm))
		dev_warn(chip->dev, "freeing PWM device without disabling\n");

	gb_pwm_deactivate_operation(pwmc, pwm->hwpwm);
}