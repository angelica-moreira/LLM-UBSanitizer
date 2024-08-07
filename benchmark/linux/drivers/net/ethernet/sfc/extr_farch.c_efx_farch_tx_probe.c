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
struct efx_tx_queue {int ptr_mask; int /*<<< orphan*/  txd; struct efx_nic* efx; } ;
struct efx_nic {int dummy; } ;
typedef  int /*<<< orphan*/  efx_qword_t ;

/* Variables and functions */
 int efx_alloc_special_buffer (struct efx_nic*,int /*<<< orphan*/ *,unsigned int) ; 

int efx_farch_tx_probe(struct efx_tx_queue *tx_queue)
{
	struct efx_nic *efx = tx_queue->efx;
	unsigned entries;

	entries = tx_queue->ptr_mask + 1;
	return efx_alloc_special_buffer(efx, &tx_queue->txd,
					entries * sizeof(efx_qword_t));
}