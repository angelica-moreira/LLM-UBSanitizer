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
struct pinctrl_dev {int dummy; } ;
struct ltq_pinmux_info {int num_funcs; } ;

/* Variables and functions */
 struct ltq_pinmux_info* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int ltq_pmx_func_count(struct pinctrl_dev *pctrldev)
{
	struct ltq_pinmux_info *info = pinctrl_dev_get_drvdata(pctrldev);

	return info->num_funcs;
}