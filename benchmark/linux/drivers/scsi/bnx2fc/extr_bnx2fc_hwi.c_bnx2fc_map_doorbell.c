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
typedef  int u32 ;
struct fcoe_port {struct bnx2fc_interface* priv; } ;
struct bnx2fc_rport {int context_id; int /*<<< orphan*/  ctx_base; struct fcoe_port* port; } ;
struct bnx2fc_interface {struct bnx2fc_hba* hba; } ;
struct bnx2fc_hba {int /*<<< orphan*/  pcidev; } ;
typedef  scalar_t__ resource_size_t ;

/* Variables and functions */
 int BNX2X_DB_SHIFT ; 
 int /*<<< orphan*/  BNX2X_DOORBELL_PCI_BAR ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ioremap_nocache (scalar_t__,int) ; 
 scalar_t__ pci_resource_start (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int bnx2fc_map_doorbell(struct bnx2fc_rport *tgt)
{
	u32 context_id = tgt->context_id;
	struct fcoe_port *port = tgt->port;
	u32 reg_off;
	resource_size_t reg_base;
	struct bnx2fc_interface *interface = port->priv;
	struct bnx2fc_hba *hba = interface->hba;

	reg_base = pci_resource_start(hba->pcidev,
					BNX2X_DOORBELL_PCI_BAR);
	reg_off = (1 << BNX2X_DB_SHIFT) * (context_id & 0x1FFFF);
	tgt->ctx_base = ioremap_nocache(reg_base + reg_off, 4);
	if (!tgt->ctx_base)
		return -ENOMEM;
	return 0;
}