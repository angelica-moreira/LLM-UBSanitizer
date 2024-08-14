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
struct tegra_devfreq {scalar_t__ regs; } ;

/* Variables and functions */
 scalar_t__ ACTMON_GLB_STATUS ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static void actmon_write_barrier(struct tegra_devfreq *tegra)
{
	/* ensure the update has reached the ACTMON */
	readl(tegra->regs + ACTMON_GLB_STATUS);
}