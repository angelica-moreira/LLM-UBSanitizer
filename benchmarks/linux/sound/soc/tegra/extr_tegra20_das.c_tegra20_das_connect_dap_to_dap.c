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
typedef  int u32 ;

/* Variables and functions */
 int ENODEV ; 
 int TEGRA20_DAS_DAP_CTRL_SEL ; 
 int TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_P ; 
 int TEGRA20_DAS_DAP_CTRL_SEL_DAP_MS_SEL_P ; 
 int TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA1_TX_RX_P ; 
 int TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA2_TX_RX_P ; 
 int TEGRA20_DAS_DAP_CTRL_SEL_STRIDE ; 
 int /*<<< orphan*/  das ; 
 int /*<<< orphan*/  tegra20_das_write (int,int) ; 

int tegra20_das_connect_dap_to_dap(int dap, int otherdap, int master,
				   int sdata1rx, int sdata2rx)
{
	u32 addr;
	u32 reg;

	if (!das)
		return -ENODEV;

	addr = TEGRA20_DAS_DAP_CTRL_SEL +
		(dap * TEGRA20_DAS_DAP_CTRL_SEL_STRIDE);
	reg = otherdap << TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_P |
		!!sdata2rx << TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA2_TX_RX_P |
		!!sdata1rx << TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA1_TX_RX_P |
		!!master << TEGRA20_DAS_DAP_CTRL_SEL_DAP_MS_SEL_P;

	tegra20_das_write(addr, reg);

	return 0;
}