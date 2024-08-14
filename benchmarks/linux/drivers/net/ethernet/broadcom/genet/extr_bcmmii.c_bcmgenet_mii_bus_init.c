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
struct device_node {int dummy; } ;
struct bcmgenet_priv {TYPE_2__* pdev; } ;
struct TYPE_3__ {struct device_node* of_node; } ;
struct TYPE_4__ {TYPE_1__ dev; } ;

/* Variables and functions */
 int bcmgenet_mii_of_init (struct bcmgenet_priv*) ; 
 int bcmgenet_mii_pd_init (struct bcmgenet_priv*) ; 

__attribute__((used)) static int bcmgenet_mii_bus_init(struct bcmgenet_priv *priv)
{
	struct device_node *dn = priv->pdev->dev.of_node;

	if (dn)
		return bcmgenet_mii_of_init(priv);
	else
		return bcmgenet_mii_pd_init(priv);
}