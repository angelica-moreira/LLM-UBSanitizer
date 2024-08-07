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
struct palmas_pctrl_chip_info {int num_pin_groups; } ;

/* Variables and functions */
 struct palmas_pctrl_chip_info* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int palmas_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
	struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);

	return pci->num_pin_groups;
}