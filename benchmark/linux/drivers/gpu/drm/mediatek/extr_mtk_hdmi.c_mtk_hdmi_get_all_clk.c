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
struct mtk_hdmi {int /*<<< orphan*/ * clk; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * mtk_hdmi_clk_names ; 
 int /*<<< orphan*/  of_clk_get_by_name (struct device_node*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mtk_hdmi_get_all_clk(struct mtk_hdmi *hdmi,
				struct device_node *np)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(mtk_hdmi_clk_names); i++) {
		hdmi->clk[i] = of_clk_get_by_name(np,
						  mtk_hdmi_clk_names[i]);
		if (IS_ERR(hdmi->clk[i]))
			return PTR_ERR(hdmi->clk[i]);
	}
	return 0;
}