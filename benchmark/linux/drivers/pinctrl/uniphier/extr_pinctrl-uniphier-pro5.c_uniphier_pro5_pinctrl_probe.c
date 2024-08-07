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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int uniphier_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uniphier_pro5_pindata ; 

__attribute__((used)) static int uniphier_pro5_pinctrl_probe(struct platform_device *pdev)
{
	return uniphier_pinctrl_probe(pdev, &uniphier_pro5_pindata);
}