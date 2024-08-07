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
struct tegra_sflash_data {int /*<<< orphan*/  clk; } ;
struct spi_master {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPI_COMMAND ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 struct spi_master* dev_get_drvdata (struct device*) ; 
 struct tegra_sflash_data* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  tegra_sflash_readl (struct tegra_sflash_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tegra_sflash_runtime_suspend(struct device *dev)
{
	struct spi_master *master = dev_get_drvdata(dev);
	struct tegra_sflash_data *tsd = spi_master_get_devdata(master);

	/* Flush all write which are in PPSB queue by reading back */
	tegra_sflash_readl(tsd, SPI_COMMAND);

	clk_disable_unprepare(tsd->clk);
	return 0;
}