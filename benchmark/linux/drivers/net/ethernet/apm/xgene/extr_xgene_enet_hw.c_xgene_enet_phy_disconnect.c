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
struct xgene_enet_pdata {struct net_device* ndev; } ;
struct net_device {scalar_t__ phydev; } ;

/* Variables and functions */
 int /*<<< orphan*/  phy_disconnect (scalar_t__) ; 

void xgene_enet_phy_disconnect(struct xgene_enet_pdata *pdata)
{
	struct net_device *ndev = pdata->ndev;

	if (ndev->phydev)
		phy_disconnect(ndev->phydev);
}