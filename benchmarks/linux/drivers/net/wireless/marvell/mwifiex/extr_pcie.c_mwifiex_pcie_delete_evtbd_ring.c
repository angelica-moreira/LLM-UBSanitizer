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
struct TYPE_2__ {struct mwifiex_pcie_card_reg* reg; } ;
struct pcie_service_card {int evtbd_rdptr; scalar_t__ evtbd_ring_pbase; int /*<<< orphan*/ * evtbd_ring_vbase; scalar_t__ evtbd_ring_size; scalar_t__ evtbd_wrptr; int /*<<< orphan*/  dev; TYPE_1__ pcie; } ;
struct mwifiex_pcie_card_reg {int evt_rollover_ind; } ;
struct mwifiex_adapter {struct pcie_service_card* card; } ;

/* Variables and functions */
 int /*<<< orphan*/  mwifiex_cleanup_evt_ring (struct mwifiex_adapter*) ; 
 int /*<<< orphan*/  pci_free_consistent (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static int mwifiex_pcie_delete_evtbd_ring(struct mwifiex_adapter *adapter)
{
	struct pcie_service_card *card = adapter->card;
	const struct mwifiex_pcie_card_reg *reg = card->pcie.reg;

	mwifiex_cleanup_evt_ring(adapter);

	if (card->evtbd_ring_vbase)
		pci_free_consistent(card->dev, card->evtbd_ring_size,
				    card->evtbd_ring_vbase,
				    card->evtbd_ring_pbase);
	card->evtbd_wrptr = 0;
	card->evtbd_rdptr = 0 | reg->evt_rollover_ind;
	card->evtbd_ring_size = 0;
	card->evtbd_ring_vbase = NULL;
	card->evtbd_ring_pbase = 0;

	return 0;
}