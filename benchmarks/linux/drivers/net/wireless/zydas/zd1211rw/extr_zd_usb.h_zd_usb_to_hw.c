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
struct zd_usb {int /*<<< orphan*/  intf; } ;
struct ieee80211_hw {int dummy; } ;

/* Variables and functions */
 struct ieee80211_hw* zd_intf_to_hw (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct ieee80211_hw *zd_usb_to_hw(struct zd_usb *usb)
{
	return zd_intf_to_hw(usb->intf);
}