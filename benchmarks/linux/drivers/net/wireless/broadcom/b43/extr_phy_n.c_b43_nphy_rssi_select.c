#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {int rev; } ;
struct b43_wldev {TYPE_1__ phy; } ;
typedef  enum n_rssi_type { ____Placeholder_n_rssi_type } n_rssi_type ;

/* Variables and functions */
 int /*<<< orphan*/  b43_nphy_rev2_rssi_select (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_nphy_rev3_rssi_select (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_nphy_rssi_select_rev19 (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void b43_nphy_rssi_select(struct b43_wldev *dev, u8 code,
				 enum n_rssi_type type)
{
	if (dev->phy.rev >= 19)
		b43_nphy_rssi_select_rev19(dev, code, type);
	else if (dev->phy.rev >= 3)
		b43_nphy_rev3_rssi_select(dev, code, type);
	else
		b43_nphy_rev2_rssi_select(dev, code, type);
}