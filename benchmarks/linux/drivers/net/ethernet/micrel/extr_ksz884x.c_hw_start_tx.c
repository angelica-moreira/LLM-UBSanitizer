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
struct ksz_hw {scalar_t__ io; int /*<<< orphan*/  tx_cfg; } ;

/* Variables and functions */
 scalar_t__ KS_DMA_TX_CTRL ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void hw_start_tx(struct ksz_hw *hw)
{
	writel(hw->tx_cfg, hw->io + KS_DMA_TX_CTRL);
}