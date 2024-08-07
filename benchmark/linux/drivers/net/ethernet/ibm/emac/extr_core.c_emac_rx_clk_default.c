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
struct emac_instance {int cell_index; } ;

/* Variables and functions */
 int /*<<< orphan*/  EMAC_FTR_440EP_PHY_CLK_FIX ; 
 int /*<<< orphan*/  SDR0 ; 
 int /*<<< orphan*/  SDR0_MFR ; 
 int SDR0_MFR_ECS ; 
 int /*<<< orphan*/  dcri_clrset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ emac_has_feature (struct emac_instance*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void emac_rx_clk_default(struct emac_instance *dev)
{
#ifdef CONFIG_PPC_DCR_NATIVE
	if (emac_has_feature(dev, EMAC_FTR_440EP_PHY_CLK_FIX))
		dcri_clrset(SDR0, SDR0_MFR,
			    SDR0_MFR_ECS >> dev->cell_index, 0);
#endif
}