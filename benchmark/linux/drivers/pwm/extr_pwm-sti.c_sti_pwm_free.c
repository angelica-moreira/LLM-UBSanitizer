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
struct sti_pwm_chip {int /*<<< orphan*/  configured; } ;
struct pwm_device {int /*<<< orphan*/  hwpwm; } ;
struct pwm_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct sti_pwm_chip* to_sti_pwmchip (struct pwm_chip*) ; 

__attribute__((used)) static void sti_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct sti_pwm_chip *pc = to_sti_pwmchip(chip);

	clear_bit(pwm->hwpwm, &pc->configured);
}