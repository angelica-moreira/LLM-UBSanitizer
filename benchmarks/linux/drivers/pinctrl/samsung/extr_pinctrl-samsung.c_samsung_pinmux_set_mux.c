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

/* Variables and functions */
 int /*<<< orphan*/  samsung_pinmux_setup (struct pinctrl_dev*,unsigned int,unsigned int) ; 

__attribute__((used)) static int samsung_pinmux_set_mux(struct pinctrl_dev *pctldev,
				  unsigned selector,
				  unsigned group)
{
	samsung_pinmux_setup(pctldev, selector, group);
	return 0;
}