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
typedef  int /*<<< orphan*/  u16 ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int ocelot_vlan_vid_add (struct net_device*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int ocelot_vlan_rx_add_vid(struct net_device *dev, __be16 proto,
				  u16 vid)
{
	return ocelot_vlan_vid_add(dev, vid, false, false);
}