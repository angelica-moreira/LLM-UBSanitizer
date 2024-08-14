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
struct ef4_nic {TYPE_1__* type; } ;
struct ef4_channel {int eventq_read_ptr; int eventq_mask; int channel; struct ef4_nic* efx; } ;
typedef  int /*<<< orphan*/  ef4_dword_t ;
struct TYPE_2__ {scalar_t__ evq_rptr_tbl_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  EF4_POPULATE_DWORD_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  FRF_AZ_EVQ_RPTR ; 
 int FR_BZ_EVQ_RPTR_STEP ; 
 int /*<<< orphan*/  ef4_writed (struct ef4_nic*,int /*<<< orphan*/ *,scalar_t__) ; 

void ef4_farch_ev_read_ack(struct ef4_channel *channel)
{
	ef4_dword_t reg;
	struct ef4_nic *efx = channel->efx;

	EF4_POPULATE_DWORD_1(reg, FRF_AZ_EVQ_RPTR,
			     channel->eventq_read_ptr & channel->eventq_mask);

	/* For Falcon A1, EVQ_RPTR_KER is documented as having a step size
	 * of 4 bytes, but it is really 16 bytes just like later revisions.
	 */
	ef4_writed(efx, &reg,
		   efx->type->evq_rptr_tbl_base +
		   FR_BZ_EVQ_RPTR_STEP * channel->channel);
}