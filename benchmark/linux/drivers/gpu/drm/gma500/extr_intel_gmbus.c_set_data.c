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
typedef  int u32 ;
struct intel_gpio {int /*<<< orphan*/  reg; struct drm_psb_private* dev_priv; } ;
struct drm_psb_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GMBUS_REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GMBUS_REG_WRITE (int /*<<< orphan*/ ,int) ; 
 int GPIO_DATA_DIR_IN ; 
 int GPIO_DATA_DIR_MASK ; 
 int GPIO_DATA_DIR_OUT ; 
 int GPIO_DATA_VAL_MASK ; 
 int get_reserved (struct intel_gpio*) ; 

__attribute__((used)) static void set_data(void *data, int state_high)
{
	struct intel_gpio *gpio = data;
	struct drm_psb_private *dev_priv = gpio->dev_priv;
	u32 reserved = get_reserved(gpio);
	u32 data_bits;

	if (state_high)
		data_bits = GPIO_DATA_DIR_IN | GPIO_DATA_DIR_MASK;
	else
		data_bits = GPIO_DATA_DIR_OUT | GPIO_DATA_DIR_MASK |
			GPIO_DATA_VAL_MASK;

	GMBUS_REG_WRITE(gpio->reg, reserved | data_bits);
	GMBUS_REG_READ(gpio->reg);
}