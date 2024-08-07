#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  size_t u16 ;
struct TYPE_11__ {int /*<<< orphan*/  used_cnt; TYPE_4__* msix; } ;
struct TYPE_7__ {int num_hwfns; } ;
struct TYPE_8__ {TYPE_1__ common; } ;
struct qedf_ctx {int num_queues; TYPE_5__ int_info; int /*<<< orphan*/  dbg_ctx; int /*<<< orphan*/ * fp_array; int /*<<< orphan*/  cdev; TYPE_2__ dev_info; } ;
struct TYPE_12__ {TYPE_3__* common; } ;
struct TYPE_10__ {int /*<<< orphan*/  vector; } ;
struct TYPE_9__ {size_t (* get_affin_hwfn_idx ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  QEDF_INFO (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int,size_t) ; 
 int /*<<< orphan*/  QEDF_LOG_DISC ; 
 int /*<<< orphan*/  QEDF_WARN (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  cpu_online_mask ; 
 int cpumask_first (int /*<<< orphan*/ ) ; 
 int cpumask_next (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_cpu_mask (int) ; 
 int irq_set_affinity_hint (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_6__* qed_ops ; 
 int /*<<< orphan*/  qedf_msix_handler ; 
 int /*<<< orphan*/  qedf_sync_free_irqs (struct qedf_ctx*) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 size_t stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int qedf_request_msix_irq(struct qedf_ctx *qedf)
{
	int i, rc, cpu;
	u16 vector_idx = 0;
	u32 vector;

	cpu = cpumask_first(cpu_online_mask);
	for (i = 0; i < qedf->num_queues; i++) {
		vector_idx = i * qedf->dev_info.common.num_hwfns +
			qed_ops->common->get_affin_hwfn_idx(qedf->cdev);
		QEDF_INFO(&qedf->dbg_ctx, QEDF_LOG_DISC,
			  "Requesting IRQ #%d vector_idx=%d.\n",
			  i, vector_idx);
		vector = qedf->int_info.msix[vector_idx].vector;
		rc = request_irq(vector, qedf_msix_handler, 0, "qedf",
				 &qedf->fp_array[i]);

		if (rc) {
			QEDF_WARN(&(qedf->dbg_ctx), "request_irq failed.\n");
			qedf_sync_free_irqs(qedf);
			return rc;
		}

		qedf->int_info.used_cnt++;
		rc = irq_set_affinity_hint(vector, get_cpu_mask(cpu));
		cpu = cpumask_next(cpu, cpu_online_mask);
	}

	return 0;
}