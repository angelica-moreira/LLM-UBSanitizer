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
struct falcon_nic_data {int /*<<< orphan*/ * pci_dev2; } ;
struct falcon_board {int /*<<< orphan*/  i2c_adap; TYPE_1__* type; } ;
struct ef4_nic {struct falcon_nic_data* nic_data; int /*<<< orphan*/  irq_status; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* fini ) (struct ef4_nic*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  RESET_TYPE_ALL ; 
 int /*<<< orphan*/  __falcon_reset_hw (struct ef4_nic*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ef4_nic_free_buffer (struct ef4_nic*,int /*<<< orphan*/ *) ; 
 struct falcon_board* falcon_board (struct ef4_nic*) ; 
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct falcon_nic_data*) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pci_dev_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct ef4_nic*) ; 

__attribute__((used)) static void falcon_remove_nic(struct ef4_nic *efx)
{
	struct falcon_nic_data *nic_data = efx->nic_data;
	struct falcon_board *board = falcon_board(efx);

	board->type->fini(efx);

	/* Remove I2C adapter and clear it in preparation for a retry */
	i2c_del_adapter(&board->i2c_adap);
	memset(&board->i2c_adap, 0, sizeof(board->i2c_adap));

	ef4_nic_free_buffer(efx, &efx->irq_status);

	__falcon_reset_hw(efx, RESET_TYPE_ALL);

	/* Release the second function after the reset */
	if (nic_data->pci_dev2) {
		pci_dev_put(nic_data->pci_dev2);
		nic_data->pci_dev2 = NULL;
	}

	/* Tear down the private nic state */
	kfree(efx->nic_data);
	efx->nic_data = NULL;
}