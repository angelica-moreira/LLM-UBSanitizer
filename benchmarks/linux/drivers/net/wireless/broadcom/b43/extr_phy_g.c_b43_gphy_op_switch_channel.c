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
struct b43_wldev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  b43_gphy_channel_switch (struct b43_wldev*,unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int b43_gphy_op_switch_channel(struct b43_wldev *dev,
				      unsigned int new_channel)
{
	if ((new_channel < 1) || (new_channel > 14))
		return -EINVAL;
	b43_gphy_channel_switch(dev, new_channel, 0);

	return 0;
}