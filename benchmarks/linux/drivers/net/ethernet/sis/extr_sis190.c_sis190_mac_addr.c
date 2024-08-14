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
struct net_device {int dummy; } ;

/* Variables and functions */
 int eth_mac_addr (struct net_device*,void*) ; 
 int /*<<< orphan*/  sis190_init_rxfilter (struct net_device*) ; 

__attribute__((used)) static int sis190_mac_addr(struct net_device  *dev, void *p)
{
	int rc;

	rc = eth_mac_addr(dev, p);
	if (!rc)
		sis190_init_rxfilter(dev);
	return rc;
}