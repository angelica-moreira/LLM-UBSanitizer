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
struct pinctrl_dev {int dummy; } ;
struct bcm2835_pinctrl {int dummy; } ;

/* Variables and functions */
 int BCM2711_PULL_DOWN ; 
 int BCM2711_PULL_NONE ; 
 int BCM2711_PULL_UP ; 
#define  BCM2835_PINCONF_PARAM_PULL 132 
 int BCM2835_PUD_DOWN ; 
 int BCM2835_PUD_UP ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GPCLR0 ; 
 int /*<<< orphan*/  GPSET0 ; 
#define  PIN_CONFIG_BIAS_DISABLE 131 
#define  PIN_CONFIG_BIAS_PULL_DOWN 130 
#define  PIN_CONFIG_BIAS_PULL_UP 129 
#define  PIN_CONFIG_OUTPUT 128 
 int /*<<< orphan*/  bcm2711_pull_config_set (struct bcm2835_pinctrl*,unsigned int,int) ; 
 int /*<<< orphan*/  bcm2835_gpio_set_bit (struct bcm2835_pinctrl*,int /*<<< orphan*/ ,unsigned int) ; 
 int pinconf_to_config_argument (unsigned long) ; 
 int pinconf_to_config_param (unsigned long) ; 
 struct bcm2835_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int bcm2711_pinconf_set(struct pinctrl_dev *pctldev,
			       unsigned int pin, unsigned long *configs,
			       unsigned int num_configs)
{
	struct bcm2835_pinctrl *pc = pinctrl_dev_get_drvdata(pctldev);
	u32 param, arg;
	int i;

	for (i = 0; i < num_configs; i++) {
		param = pinconf_to_config_param(configs[i]);
		arg = pinconf_to_config_argument(configs[i]);

		switch (param) {
		/* convert legacy brcm,pull */
		case BCM2835_PINCONF_PARAM_PULL:
			if (arg == BCM2835_PUD_UP)
				arg = BCM2711_PULL_UP;
			else if (arg == BCM2835_PUD_DOWN)
				arg = BCM2711_PULL_DOWN;
			else
				arg = BCM2711_PULL_NONE;

			bcm2711_pull_config_set(pc, pin, arg);
			break;

		/* Set pull generic bindings */
		case PIN_CONFIG_BIAS_DISABLE:
			bcm2711_pull_config_set(pc, pin, BCM2711_PULL_NONE);
			break;
		case PIN_CONFIG_BIAS_PULL_DOWN:
			bcm2711_pull_config_set(pc, pin, BCM2711_PULL_DOWN);
			break;
		case PIN_CONFIG_BIAS_PULL_UP:
			bcm2711_pull_config_set(pc, pin, BCM2711_PULL_UP);
			break;

		/* Set output-high or output-low */
		case PIN_CONFIG_OUTPUT:
			bcm2835_gpio_set_bit(pc, arg ? GPSET0 : GPCLR0, pin);
			break;

		default:
			return -ENOTSUPP;
		}
	} /* for each config */

	return 0;
}