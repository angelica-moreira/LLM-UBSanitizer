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
struct b43_phy {int radio_ver; int radio_rev; } ;
struct b43_wldev {struct b43_phy phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  B43_MMIO_CHANNEL ; 
 int /*<<< orphan*/  b43_write16 (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  channel2freq_bg (int) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static void b43_synth_pu_workaround(struct b43_wldev *dev, u8 channel)
{
	struct b43_phy *phy = &dev->phy;

	might_sleep();

	if (phy->radio_ver != 0x2050 || phy->radio_rev >= 6) {
		/* We do not need the workaround. */
		return;
	}

	if (channel <= 10) {
		b43_write16(dev, B43_MMIO_CHANNEL,
			    channel2freq_bg(channel + 4));
	} else {
		b43_write16(dev, B43_MMIO_CHANNEL, channel2freq_bg(1));
	}
	msleep(1);
	b43_write16(dev, B43_MMIO_CHANNEL, channel2freq_bg(channel));
}