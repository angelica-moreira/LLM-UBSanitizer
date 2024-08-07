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
struct sci_sas_address {void* low; void* high; } ;
struct isci_phy {TYPE_1__* link_layer_registers; } ;
struct TYPE_2__ {int /*<<< orphan*/  source_sas_address_low; int /*<<< orphan*/  source_sas_address_high; } ;

/* Variables and functions */
 void* readl (int /*<<< orphan*/ *) ; 

void sci_phy_get_sas_address(struct isci_phy *iphy, struct sci_sas_address *sas)
{
	sas->high = readl(&iphy->link_layer_registers->source_sas_address_high);
	sas->low = readl(&iphy->link_layer_registers->source_sas_address_low);
}