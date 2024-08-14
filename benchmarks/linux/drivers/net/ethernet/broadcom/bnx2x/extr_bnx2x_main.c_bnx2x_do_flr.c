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
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {scalar_t__ bc_ver; } ;
struct bnx2x {TYPE_1__ common; struct pci_dev* pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNX2X_DEV_INFO (char*) ; 
 int /*<<< orphan*/  BNX2X_ERR (char*,scalar_t__) ; 
 scalar_t__ CHIP_IS_E1x (struct bnx2x*) ; 
 int /*<<< orphan*/  DRV_MSG_CODE_INITIATE_FLR ; 
 int EINVAL ; 
 scalar_t__ REQ_BC_VER_4_INITIATE_FLR ; 
 int /*<<< orphan*/  bnx2x_fw_command (struct bnx2x*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  pci_wait_for_pending_transaction (struct pci_dev*) ; 

__attribute__((used)) static int bnx2x_do_flr(struct bnx2x *bp)
{
	struct pci_dev *dev = bp->pdev;

	if (CHIP_IS_E1x(bp)) {
		BNX2X_DEV_INFO("FLR not supported in E1/E1H\n");
		return -EINVAL;
	}

	/* only bootcode REQ_BC_VER_4_INITIATE_FLR and onwards support flr */
	if (bp->common.bc_ver < REQ_BC_VER_4_INITIATE_FLR) {
		BNX2X_ERR("FLR not supported by BC_VER: 0x%x\n",
			  bp->common.bc_ver);
		return -EINVAL;
	}

	if (!pci_wait_for_pending_transaction(dev))
		dev_err(&dev->dev, "transaction is not cleared; proceeding with reset anyway\n");

	BNX2X_DEV_INFO("Initiating FLR\n");
	bnx2x_fw_command(bp, DRV_MSG_CODE_INITIATE_FLR, 0);

	return 0;
}