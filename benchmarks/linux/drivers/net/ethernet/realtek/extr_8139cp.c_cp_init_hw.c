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
struct net_device {scalar_t__ dev_addr; } ;
struct cp_private {scalar_t__ wol_enabled; struct net_device* dev; } ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  Cfg9346 ; 
 int /*<<< orphan*/  Cfg9346_Lock ; 
 int /*<<< orphan*/  Cfg9346_Unlock ; 
 int /*<<< orphan*/  Config1 ; 
 int /*<<< orphan*/  Config3 ; 
 int /*<<< orphan*/  Config5 ; 
 int DriverLoaded ; 
 int IFG ; 
 scalar_t__ MAC0 ; 
 int /*<<< orphan*/  MultiIntr ; 
 int PARMEnable ; 
 int PMEStatus ; 
 int PMEnable ; 
 int TX_DMA_BURST ; 
 scalar_t__ TxConfig ; 
 int TxDMAShift ; 
 int /*<<< orphan*/  TxThresh ; 
 int /*<<< orphan*/  __cp_set_rx_mode (struct net_device*) ; 
 int /*<<< orphan*/  cp_reset_hw (struct cp_private*) ; 
 int /*<<< orphan*/  cp_start_hw (struct cp_private*) ; 
 int cpr8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpw16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpw32_f (scalar_t__,int) ; 
 int /*<<< orphan*/  cpw8 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cpw8_f (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cp_init_hw (struct cp_private *cp)
{
	struct net_device *dev = cp->dev;

	cp_reset_hw(cp);

	cpw8_f (Cfg9346, Cfg9346_Unlock);

	/* Restore our idea of the MAC address. */
	cpw32_f (MAC0 + 0, le32_to_cpu (*(__le32 *) (dev->dev_addr + 0)));
	cpw32_f (MAC0 + 4, le32_to_cpu (*(__le32 *) (dev->dev_addr + 4)));

	cp_start_hw(cp);
	cpw8(TxThresh, 0x06); /* XXX convert magic num to a constant */

	__cp_set_rx_mode(dev);
	cpw32_f (TxConfig, IFG | (TX_DMA_BURST << TxDMAShift));

	cpw8(Config1, cpr8(Config1) | DriverLoaded | PMEnable);
	/* Disable Wake-on-LAN. Can be turned on with ETHTOOL_SWOL */
	cpw8(Config3, PARMEnable);
	cp->wol_enabled = 0;

	cpw8(Config5, cpr8(Config5) & PMEStatus);

	cpw16(MultiIntr, 0);

	cpw8_f(Cfg9346, Cfg9346_Lock);
}