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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct rt2x00_dev {int dummy; } ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_hw {struct rt2x00_dev* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  TXRX_CSR12 ; 
 int /*<<< orphan*/  TXRX_CSR12_LOW_TSFTIMER ; 
 int /*<<< orphan*/  TXRX_CSR13 ; 
 int /*<<< orphan*/  TXRX_CSR13_HIGH_TSFTIMER ; 
 int rt2x00_get_field32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00usb_register_read (struct rt2x00_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u64 rt73usb_get_tsf(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
	struct rt2x00_dev *rt2x00dev = hw->priv;
	u64 tsf;
	u32 reg;

	reg = rt2x00usb_register_read(rt2x00dev, TXRX_CSR13);
	tsf = (u64) rt2x00_get_field32(reg, TXRX_CSR13_HIGH_TSFTIMER) << 32;
	reg = rt2x00usb_register_read(rt2x00dev, TXRX_CSR12);
	tsf |= rt2x00_get_field32(reg, TXRX_CSR12_LOW_TSFTIMER);

	return tsf;
}