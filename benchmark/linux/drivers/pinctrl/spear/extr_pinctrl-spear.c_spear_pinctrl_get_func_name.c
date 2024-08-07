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
struct spear_pmx {TYPE_2__* machdata; } ;
struct pinctrl_dev {int dummy; } ;
struct TYPE_4__ {TYPE_1__** functions; } ;
struct TYPE_3__ {char const* name; } ;

/* Variables and functions */
 struct spear_pmx* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static const char *spear_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
		unsigned function)
{
	struct spear_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);

	return pmx->machdata->functions[function]->name;
}