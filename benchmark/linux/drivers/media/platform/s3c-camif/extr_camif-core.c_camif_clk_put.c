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
struct camif_dev {int /*<<< orphan*/ * clock; } ;

/* Variables and functions */
 int CLK_MAX_NUM ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void camif_clk_put(struct camif_dev *camif)
{
	int i;

	for (i = 0; i < CLK_MAX_NUM; i++) {
		if (IS_ERR(camif->clock[i]))
			continue;
		clk_unprepare(camif->clock[i]);
		clk_put(camif->clock[i]);
		camif->clock[i] = ERR_PTR(-EINVAL);
	}
}