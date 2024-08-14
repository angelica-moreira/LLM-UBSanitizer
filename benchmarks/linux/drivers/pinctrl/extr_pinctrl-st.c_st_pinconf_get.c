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
struct st_pio_control {int dummy; } ;
struct st_pinctrl {int dummy; } ;
struct pinctrl_dev {int dummy; } ;

/* Variables and functions */
 struct st_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 
 struct st_pio_control* st_get_pio_control (struct pinctrl_dev*,unsigned int) ; 
 int st_gpio_pin (unsigned int) ; 
 int /*<<< orphan*/  st_pinconf_get_direction (struct st_pio_control*,int,unsigned long*) ; 
 int /*<<< orphan*/  st_pinconf_get_retime (struct st_pinctrl*,struct st_pio_control*,int,unsigned long*) ; 

__attribute__((used)) static int st_pinconf_get(struct pinctrl_dev *pctldev,
			     unsigned pin_id, unsigned long *config)
{
	int pin = st_gpio_pin(pin_id);
	struct st_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
	struct st_pio_control *pc = st_get_pio_control(pctldev, pin_id);

	*config = 0;
	st_pinconf_get_direction(pc, pin, config);
	st_pinconf_get_retime(info, pc, pin, config);

	return 0;
}