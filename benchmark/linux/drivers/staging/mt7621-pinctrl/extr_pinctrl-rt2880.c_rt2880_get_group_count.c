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
struct rt2880_priv {int group_count; } ;
struct pinctrl_dev {int dummy; } ;

/* Variables and functions */
 struct rt2880_priv* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int rt2880_get_group_count(struct pinctrl_dev *pctrldev)
{
	struct rt2880_priv *p = pinctrl_dev_get_drvdata(pctrldev);

	return p->group_count;
}