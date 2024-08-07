#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct lpfc_mbx_nembed_cmd {TYPE_4__* sge; } ;
struct TYPE_5__ {int /*<<< orphan*/  nembed_cmd; } ;
struct TYPE_6__ {TYPE_1__ un; } ;
struct TYPE_7__ {TYPE_2__ mqe; } ;
struct lpfcMboxq {TYPE_3__ u; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
struct TYPE_8__ {size_t length; int /*<<< orphan*/  pa_hi; int /*<<< orphan*/  pa_lo; } ;

/* Variables and functions */
 int /*<<< orphan*/  putPaddrHigh (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  putPaddrLow (int /*<<< orphan*/ ) ; 

void
lpfc_sli4_mbx_sge_set(struct lpfcMboxq *mbox, uint32_t sgentry,
		      dma_addr_t phyaddr, uint32_t length)
{
	struct lpfc_mbx_nembed_cmd *nembed_sge;

	nembed_sge = (struct lpfc_mbx_nembed_cmd *)
				&mbox->u.mqe.un.nembed_cmd;
	nembed_sge->sge[sgentry].pa_lo = putPaddrLow(phyaddr);
	nembed_sge->sge[sgentry].pa_hi = putPaddrHigh(phyaddr);
	nembed_sge->sge[sgentry].length = length;
}