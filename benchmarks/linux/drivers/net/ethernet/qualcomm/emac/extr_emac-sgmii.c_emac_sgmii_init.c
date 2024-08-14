#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* sgmii_ops; } ;
struct emac_adapter {TYPE_2__ phy; } ;
struct TYPE_3__ {int (* init ) (struct emac_adapter*) ;} ;

/* Variables and functions */
 int stub1 (struct emac_adapter*) ; 

int emac_sgmii_init(struct emac_adapter *adpt)
{
	if (!(adpt->phy.sgmii_ops && adpt->phy.sgmii_ops->init))
		return 0;

	return adpt->phy.sgmii_ops->init(adpt);
}