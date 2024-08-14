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
struct imx1_pinctrl {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MX1_PUEN ; 
 unsigned long imx1_read_bit (struct imx1_pinctrl*,unsigned int,int /*<<< orphan*/ ) ; 
 struct imx1_pinctrl* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static int imx1_pinconf_get(struct pinctrl_dev *pctldev,
			     unsigned pin_id, unsigned long *config)
{
	struct imx1_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);

	*config = imx1_read_bit(ipctl, pin_id, MX1_PUEN);

	return 0;
}