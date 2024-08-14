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
struct bnxt_hw_resc {scalar_t__ resv_tx_rings; scalar_t__ min_tx_rings; } ;
struct bnxt {int /*<<< orphan*/  dev; struct bnxt_hw_resc hw_resc; } ;

/* Variables and functions */
 scalar_t__ BNXT_NEW_RM (struct bnxt*) ; 
 scalar_t__ BNXT_VF (struct bnxt*) ; 
 int /*<<< orphan*/  netif_running (int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool bnxt_can_reserve_rings(struct bnxt *bp)
{
#ifdef CONFIG_BNXT_SRIOV
	if (BNXT_NEW_RM(bp) && BNXT_VF(bp)) {
		struct bnxt_hw_resc *hw_resc = &bp->hw_resc;

		/* No minimum rings were provisioned by the PF.  Don't
		 * reserve rings by default when device is down.
		 */
		if (hw_resc->min_tx_rings || hw_resc->resv_tx_rings)
			return true;

		if (!netif_running(bp->dev))
			return false;
	}
#endif
	return true;
}