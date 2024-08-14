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
struct mtk_mdp_comp {int /*<<< orphan*/  dev_node; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  of_node_put (int /*<<< orphan*/ ) ; 

void mtk_mdp_comp_deinit(struct device *dev, struct mtk_mdp_comp *comp)
{
	of_node_put(comp->dev_node);
}