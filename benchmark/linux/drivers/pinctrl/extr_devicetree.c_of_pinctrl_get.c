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
struct device_node {int dummy; } ;

/* Variables and functions */
 struct pinctrl_dev* get_pinctrl_dev_from_of_node (struct device_node*) ; 

struct pinctrl_dev *of_pinctrl_get(struct device_node *np)
{
	return get_pinctrl_dev_from_of_node(np);
}