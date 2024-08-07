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
typedef  int u8 ;
typedef  int u32 ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rtl8187se_three_wire_io (struct ieee80211_hw*,int*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 rtl8187se_rf_readreg(struct ieee80211_hw *dev, u8 addr)
{
	u32 dataread = addr & 0x0F;
	rtl8187se_three_wire_io(dev, (u8 *)&dataread, 16, 0);
	return dataread;
}