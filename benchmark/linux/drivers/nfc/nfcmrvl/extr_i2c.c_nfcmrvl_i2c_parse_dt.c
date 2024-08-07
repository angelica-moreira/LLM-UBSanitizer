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
struct nfcmrvl_platform_data {int irq; int /*<<< orphan*/  irq_polarity; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQF_TRIGGER_FALLING ; 
 int /*<<< orphan*/  IRQF_TRIGGER_RISING ; 
 int irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int nfcmrvl_parse_dt (struct device_node*,struct nfcmrvl_platform_data*) ; 
 scalar_t__ of_find_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 

__attribute__((used)) static int nfcmrvl_i2c_parse_dt(struct device_node *node,
				struct nfcmrvl_platform_data *pdata)
{
	int ret;

	ret = nfcmrvl_parse_dt(node, pdata);
	if (ret < 0) {
		pr_err("Failed to get generic entries\n");
		return ret;
	}

	if (of_find_property(node, "i2c-int-falling", NULL))
		pdata->irq_polarity = IRQF_TRIGGER_FALLING;
	else
		pdata->irq_polarity = IRQF_TRIGGER_RISING;

	ret = irq_of_parse_and_map(node, 0);
	if (ret < 0) {
		pr_err("Unable to get irq, error: %d\n", ret);
		return ret;
	}
	pdata->irq = ret;

	return 0;
}