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
struct zynq_pinctrl {TYPE_1__* groups; } ;
struct pinctrl_dev {int dummy; } ;
struct TYPE_2__ {unsigned int* pins; unsigned int npins; } ;

/* Variables and functions */
 struct zynq_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int zynq_pctrl_get_group_pins(struct pinctrl_dev *pctldev,
				     unsigned int selector,
				     const unsigned int **pins,
				     unsigned int *num_pins)
{
	struct zynq_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);

	*pins = pctrl->groups[selector].pins;
	*num_pins = pctrl->groups[selector].npins;

	return 0;
}