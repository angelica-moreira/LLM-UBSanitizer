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
typedef  int /*<<< orphan*/  u32 ;
struct spear_pwm_chip {int /*<<< orphan*/  clk; } ;
struct pwm_device {int /*<<< orphan*/  hwpwm; } ;
struct pwm_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PWMCR ; 
 int /*<<< orphan*/  PWMCR_PWM_ENABLE ; 
 int clk_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spear_pwm_readl (struct spear_pwm_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spear_pwm_writel (struct spear_pwm_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct spear_pwm_chip* to_spear_pwm_chip (struct pwm_chip*) ; 

__attribute__((used)) static int spear_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct spear_pwm_chip *pc = to_spear_pwm_chip(chip);
	int rc = 0;
	u32 val;

	rc = clk_enable(pc->clk);
	if (rc)
		return rc;

	val = spear_pwm_readl(pc, pwm->hwpwm, PWMCR);
	val |= PWMCR_PWM_ENABLE;
	spear_pwm_writel(pc, pwm->hwpwm, PWMCR, val);

	return 0;
}