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
struct pxa_pinctrl_group {char const* name; } ;
struct pxa_pinctrl {struct pxa_pinctrl_group* groups; } ;
struct pinctrl_dev {int dummy; } ;

/* Variables and functions */
 struct pxa_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static const char *pxa2xx_pctrl_get_group_name(struct pinctrl_dev *pctldev,
					       unsigned tgroup)
{
	struct pxa_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
	struct pxa_pinctrl_group *group = pctl->groups + tgroup;

	return group->name;
}