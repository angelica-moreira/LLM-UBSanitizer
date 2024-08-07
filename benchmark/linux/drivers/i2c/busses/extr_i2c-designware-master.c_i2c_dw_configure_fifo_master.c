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
struct dw_i2c_dev {int tx_fifo_depth; int master_cfg; } ;

/* Variables and functions */
 int /*<<< orphan*/  DW_IC_CON ; 
 int /*<<< orphan*/  DW_IC_RX_TL ; 
 int /*<<< orphan*/  DW_IC_TX_TL ; 
 int /*<<< orphan*/  dw_writel (struct dw_i2c_dev*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void i2c_dw_configure_fifo_master(struct dw_i2c_dev *dev)
{
	/* Configure Tx/Rx FIFO threshold levels */
	dw_writel(dev, dev->tx_fifo_depth / 2, DW_IC_TX_TL);
	dw_writel(dev, 0, DW_IC_RX_TL);

	/* Configure the I2C master */
	dw_writel(dev, dev->master_cfg, DW_IC_CON);
}