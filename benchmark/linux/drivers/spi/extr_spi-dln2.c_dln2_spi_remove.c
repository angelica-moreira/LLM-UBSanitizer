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
struct spi_master {int dummy; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct dln2_spi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ dln2_spi_enable (struct dln2_spi*,int) ; 
 int /*<<< orphan*/  platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  pm_runtime_disable (int /*<<< orphan*/ *) ; 
 struct spi_master* spi_master_get (int /*<<< orphan*/ ) ; 
 struct dln2_spi* spi_master_get_devdata (struct spi_master*) ; 

__attribute__((used)) static int dln2_spi_remove(struct platform_device *pdev)
{
	struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
	struct dln2_spi *dln2 = spi_master_get_devdata(master);

	pm_runtime_disable(&pdev->dev);

	if (dln2_spi_enable(dln2, false) < 0)
		dev_err(&pdev->dev, "Failed to disable SPI module\n");

	return 0;
}