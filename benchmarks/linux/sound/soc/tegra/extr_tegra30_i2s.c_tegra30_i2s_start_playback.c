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
struct tegra30_i2s {int /*<<< orphan*/  regmap; int /*<<< orphan*/  playback_fifo_cif; } ;

/* Variables and functions */
 int /*<<< orphan*/  TEGRA30_I2S_CTRL ; 
 int /*<<< orphan*/  TEGRA30_I2S_CTRL_XFER_EN_TX ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tegra30_ahub_enable_tx_fifo (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tegra30_i2s_start_playback(struct tegra30_i2s *i2s)
{
	tegra30_ahub_enable_tx_fifo(i2s->playback_fifo_cif);
	regmap_update_bits(i2s->regmap, TEGRA30_I2S_CTRL,
			   TEGRA30_I2S_CTRL_XFER_EN_TX,
			   TEGRA30_I2S_CTRL_XFER_EN_TX);
}