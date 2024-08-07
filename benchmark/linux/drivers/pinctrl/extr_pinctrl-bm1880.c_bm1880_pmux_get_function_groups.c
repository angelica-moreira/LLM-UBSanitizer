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
struct bm1880_pinctrl {TYPE_1__* funcs; } ;
struct TYPE_2__ {char** groups; unsigned int ngroups; } ;

/* Variables and functions */
 struct bm1880_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int bm1880_pmux_get_function_groups(struct pinctrl_dev *pctldev,
					   unsigned int selector,
					   const char * const **groups,
					   unsigned * const num_groups)
{
	struct bm1880_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);

	*groups = pctrl->funcs[selector].groups;
	*num_groups = pctrl->funcs[selector].ngroups;
	return 0;
}