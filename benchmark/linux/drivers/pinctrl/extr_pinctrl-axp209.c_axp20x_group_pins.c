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
struct pinctrl_dev {int dummy; } ;
struct axp20x_pctl {TYPE_1__* desc; } ;
struct TYPE_2__ {int /*<<< orphan*/ * pins; } ;

/* Variables and functions */
 struct axp20x_pctl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int axp20x_group_pins(struct pinctrl_dev *pctldev, unsigned int selector,
			     const unsigned int **pins, unsigned int *num_pins)
{
	struct axp20x_pctl *pctl = pinctrl_dev_get_drvdata(pctldev);

	*pins = (unsigned int *)&pctl->desc->pins[selector];
	*num_pins = 1;

	return 0;
}