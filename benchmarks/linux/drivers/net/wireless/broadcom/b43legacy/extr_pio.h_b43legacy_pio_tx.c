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
struct sk_buff {int dummy; } ;
struct b43legacy_wldev {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline
int b43legacy_pio_tx(struct b43legacy_wldev *dev,
		   struct sk_buff *skb)
{
	return 0;
}