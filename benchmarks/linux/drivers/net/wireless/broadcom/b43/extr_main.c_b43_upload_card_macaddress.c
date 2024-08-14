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
struct b43_wldev {TYPE_1__* wl; } ;
struct TYPE_2__ {int /*<<< orphan*/  mac_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MACFILTER_SELF ; 
 int /*<<< orphan*/  b43_macfilter_set (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_write_mac_bssid_templates (struct b43_wldev*) ; 

__attribute__((used)) static void b43_upload_card_macaddress(struct b43_wldev *dev)
{
	b43_write_mac_bssid_templates(dev);
	b43_macfilter_set(dev, B43_MACFILTER_SELF, dev->wl->mac_addr);
}