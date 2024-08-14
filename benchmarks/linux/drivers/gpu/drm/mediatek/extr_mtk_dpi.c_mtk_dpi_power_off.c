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
struct mtk_dpi {scalar_t__ refcount; int /*<<< orphan*/  engine_clk; int /*<<< orphan*/  pixel_clk; } ;

/* Variables and functions */
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_dpi_disable (struct mtk_dpi*) ; 

__attribute__((used)) static void mtk_dpi_power_off(struct mtk_dpi *dpi)
{
	if (WARN_ON(dpi->refcount == 0))
		return;

	if (--dpi->refcount != 0)
		return;

	mtk_dpi_disable(dpi);
	clk_disable_unprepare(dpi->pixel_clk);
	clk_disable_unprepare(dpi->engine_clk);
}