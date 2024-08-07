#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_8__ {int /*<<< orphan*/  rxframgment; } ;
struct r8192_priv {TYPE_2__ stats; } ;
struct net_device {int dummy; } ;
struct ieee80211_rx_stats {int /*<<< orphan*/  virtual_address; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* GetHwRegHandler ) (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct TYPE_9__ {TYPE_1__ HalFunc; int /*<<< orphan*/  bInHctTest; } ;
typedef  scalar_t__ RT_RF_POWER_STATE ;

/* Variables and functions */
 TYPE_3__* Adapter ; 
 int /*<<< orphan*/  CountRxErrStatistics (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HW_VAR_RF_STATE ; 
 int /*<<< orphan*/  RmMonitorSignalStrength (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SwCrcCheck () ; 
 scalar_t__ eRfOff ; 
 scalar_t__ get_rxpacket_shiftbytes_819xusb (struct ieee80211_rx_stats*) ; 
 struct r8192_priv* ieee80211_priv (struct net_device*) ; 
 int /*<<< orphan*/  pRfd ; 
 scalar_t__ rtl819xusb_rx_command_packet (struct net_device*,struct ieee80211_rx_stats*) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rtl819xusb_process_received_packet(
		struct net_device *dev,
		struct ieee80211_rx_stats *pstats)
{
	struct r8192_priv *priv = ieee80211_priv(dev);

	/* Get shifted bytes of Starting address of 802.11 header. */
	pstats->virtual_address += get_rxpacket_shiftbytes_819xusb(pstats);
#ifdef TODO	/* about HCT */
	if (!Adapter->bInHctTest)
		CountRxErrStatistics(Adapter, pRfd);
#endif
#ifdef ENABLE_PS  /* for adding ps function in future */
	RT_RF_POWER_STATE rtState;
	/* When RF is off, we should not count the packet for hw/sw synchronize
	 * reason, ie. there may be a duration while sw switch is changed and
	 * hw switch is being changed.
	 */
	Adapter->HalFunc.GetHwRegHandler(Adapter, HW_VAR_RF_STATE,
					 (u8 *)(&rtState));
	if (rtState == eRfOff)
		return;
#endif
	priv->stats.rxframgment++;

#ifdef TODO
	RmMonitorSignalStrength(Adapter, pRfd);
#endif
	/* We have to release RFD and return if rx pkt is cmd pkt. */
	if (rtl819xusb_rx_command_packet(dev, pstats))
		return;

#ifdef SW_CRC_CHECK
	SwCrcCheck();
#endif


}