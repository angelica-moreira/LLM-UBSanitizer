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
struct sas_phy {int /*<<< orphan*/  negotiated_linkrate; } ;
struct asd_sas_phy {struct sas_phy* phy; } ;
struct hisi_sas_phy {int /*<<< orphan*/  lock; scalar_t__ enable; int /*<<< orphan*/ * port; scalar_t__ phy_type; scalar_t__ phy_attached; struct asd_sas_phy sas_phy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SAS_LINK_RATE_UNKNOWN ; 
 int /*<<< orphan*/  SAS_PHY_DISABLED ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void hisi_sas_phy_disconnected(struct hisi_sas_phy *phy)
{
	struct asd_sas_phy *sas_phy = &phy->sas_phy;
	struct sas_phy *sphy = sas_phy->phy;
	unsigned long flags;

	phy->phy_attached = 0;
	phy->phy_type = 0;
	phy->port = NULL;

	spin_lock_irqsave(&phy->lock, flags);
	if (phy->enable)
		sphy->negotiated_linkrate = SAS_LINK_RATE_UNKNOWN;
	else
		sphy->negotiated_linkrate = SAS_PHY_DISABLED;
	spin_unlock_irqrestore(&phy->lock, flags);
}