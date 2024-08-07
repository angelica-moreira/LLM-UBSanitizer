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
struct img_prl_out {int /*<<< orphan*/  clk_ref; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 struct img_prl_out* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int img_prl_out_resume(struct device *dev)
{
	struct img_prl_out *prl = dev_get_drvdata(dev);
	int ret;

	ret = clk_prepare_enable(prl->clk_ref);
	if (ret) {
		dev_err(dev, "clk_enable failed: %d\n", ret);
		return ret;
	}

	return 0;
}