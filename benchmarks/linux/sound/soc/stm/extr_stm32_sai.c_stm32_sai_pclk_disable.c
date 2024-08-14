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
struct stm32_sai_data {int /*<<< orphan*/  pclk; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct stm32_sai_data* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int stm32_sai_pclk_disable(struct device *dev)
{
	struct stm32_sai_data *sai = dev_get_drvdata(dev);

	clk_disable_unprepare(sai->pclk);

	return 0;
}