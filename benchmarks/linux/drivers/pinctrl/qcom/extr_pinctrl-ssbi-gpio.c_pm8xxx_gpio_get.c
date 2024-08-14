#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct pm8xxx_pin_data {scalar_t__ mode; int output_value; scalar_t__ irq; } ;
struct TYPE_4__ {TYPE_1__* pins; } ;
struct pm8xxx_gpio {TYPE_2__ desc; } ;
struct gpio_chip {int dummy; } ;
struct TYPE_3__ {struct pm8xxx_pin_data* drv_data; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IRQCHIP_STATE_LINE_LEVEL ; 
 scalar_t__ PM8XXX_GPIO_MODE_OUTPUT ; 
 struct pm8xxx_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int irq_get_irqchip_state (scalar_t__,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int pm8xxx_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
	struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
	bool state;
	int ret;

	if (pin->mode == PM8XXX_GPIO_MODE_OUTPUT) {
		ret = pin->output_value;
	} else if (pin->irq >= 0) {
		ret = irq_get_irqchip_state(pin->irq, IRQCHIP_STATE_LINE_LEVEL, &state);
		if (!ret)
			ret = !!state;
	} else
		ret = -EINVAL;

	return ret;
}