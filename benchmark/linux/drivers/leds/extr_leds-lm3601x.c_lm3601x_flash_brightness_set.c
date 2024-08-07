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
typedef  int u8 ;
typedef  int u32 ;
struct lm3601x_led {int /*<<< orphan*/  lock; int /*<<< orphan*/  regmap; } ;
struct led_classdev_flash {int dummy; } ;

/* Variables and functions */
 int LED_OFF ; 
 int /*<<< orphan*/  LM3601X_ENABLE_REG ; 
 int /*<<< orphan*/  LM3601X_LED_FLASH_REG ; 
 int /*<<< orphan*/  LM3601X_MODE_STROBE ; 
 int LM3601X_STROBE_REG_DIV ; 
 struct lm3601x_led* fled_cdev_to_led (struct led_classdev_flash*) ; 
 int lm3601x_read_faults (struct lm3601x_led*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int lm3601x_flash_brightness_set(struct led_classdev_flash *fled_cdev,
					u32 brightness)
{
	struct lm3601x_led *led = fled_cdev_to_led(fled_cdev);
	u8 brightness_val;
	int ret;

	mutex_lock(&led->lock);
	ret = lm3601x_read_faults(led);
	if (ret < 0)
		goto out;

	if (brightness == LED_OFF) {
		ret = regmap_update_bits(led->regmap, LM3601X_ENABLE_REG,
					LM3601X_MODE_STROBE, LED_OFF);
		goto out;
	}

	brightness_val = brightness / LM3601X_STROBE_REG_DIV;

	ret = regmap_write(led->regmap, LM3601X_LED_FLASH_REG, brightness_val);
out:
	mutex_unlock(&led->lock);
	return ret;
}