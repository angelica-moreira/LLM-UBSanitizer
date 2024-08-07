#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {struct device_node* of_node; } ;
struct platform_device {int /*<<< orphan*/  name; TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct clk_onecell_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLK_PCIE_NR_CLK ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int /*<<< orphan*/ ,int) ; 
 struct clk_onecell_data* mtk_alloc_clk_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_clk_register_gates (struct device_node*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct clk_onecell_data*) ; 
 int /*<<< orphan*/  mtk_register_reset_controller (struct device_node*,int,int) ; 
 int of_clk_add_provider (struct device_node*,int /*<<< orphan*/ ,struct clk_onecell_data*) ; 
 int /*<<< orphan*/  of_clk_src_onecell_get ; 
 int /*<<< orphan*/  pcie_clks ; 

__attribute__((used)) static int clk_mt7629_pciesys_init(struct platform_device *pdev)
{
	struct clk_onecell_data *clk_data;
	struct device_node *node = pdev->dev.of_node;
	int r;

	clk_data = mtk_alloc_clk_data(CLK_PCIE_NR_CLK);

	mtk_clk_register_gates(node, pcie_clks, ARRAY_SIZE(pcie_clks),
			       clk_data);

	r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
	if (r)
		dev_err(&pdev->dev,
			"could not register clock provider: %s: %d\n",
			pdev->name, r);

	mtk_register_reset_controller(node, 1, 0x34);

	return r;
}