#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct pistachio_pinctrl {TYPE_1__* groups; } ;
struct pinctrl_dev {int dummy; } ;
struct TYPE_2__ {unsigned int pin; } ;

/* Variables and functions */
 struct pistachio_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int pistachio_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
					    unsigned group,
					    const unsigned **pins,
					    unsigned *num_pins)
{
	struct pistachio_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);

	*pins = &pctl->groups[group].pin;
	*num_pins = 1;

	return 0;
}