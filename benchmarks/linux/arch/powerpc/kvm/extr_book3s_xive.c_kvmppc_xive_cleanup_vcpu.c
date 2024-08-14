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
struct xive_q {int /*<<< orphan*/ * qpage; } ;
struct kvmppc_xive_vcpu {int valid; scalar_t__ vp_ipi; int /*<<< orphan*/  vp_ipi_data; int /*<<< orphan*/  vp_id; struct xive_q* queues; struct kvmppc_xive_vcpu** esc_virq_names; scalar_t__* esc_virq; TYPE_3__* xive; int /*<<< orphan*/  server_num; } ;
struct kvmppc_xive {int /*<<< orphan*/  q_page_order; } ;
struct TYPE_8__ {struct kvmppc_xive_vcpu* xive_vcpu; int /*<<< orphan*/  irq_type; scalar_t__ xive_cam_word; } ;
struct kvm_vcpu {TYPE_4__ arch; TYPE_2__* kvm; } ;
struct TYPE_7__ {scalar_t__ single_escalation; } ;
struct TYPE_5__ {struct kvmppc_xive* xive; } ;
struct TYPE_6__ {TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  KVMPPC_IRQ_DEFAULT ; 
 int KVMPPC_XIVE_Q_COUNT ; 
 int /*<<< orphan*/  XIVE_ESB_SET_PQ_01 ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct kvm_vcpu*) ; 
 int /*<<< orphan*/  free_pages (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_dispose_mapping (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct kvmppc_xive_vcpu*) ; 
 int /*<<< orphan*/  kvmppc_xics_enabled (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  kvmppc_xive_disable_vcpu_interrupts (struct kvm_vcpu*) ; 
 int /*<<< orphan*/  pr_devel (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xive_cleanup_irq_data (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xive_cleanup_single_escalation (struct kvm_vcpu*,struct kvmppc_xive_vcpu*,scalar_t__) ; 
 int /*<<< orphan*/  xive_native_disable_queue (int /*<<< orphan*/ ,struct xive_q*,int) ; 
 int /*<<< orphan*/  xive_native_disable_vp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xive_native_free_irq (scalar_t__) ; 
 int /*<<< orphan*/  xive_vm_esb_load (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void kvmppc_xive_cleanup_vcpu(struct kvm_vcpu *vcpu)
{
	struct kvmppc_xive_vcpu *xc = vcpu->arch.xive_vcpu;
	struct kvmppc_xive *xive = vcpu->kvm->arch.xive;
	int i;

	if (!kvmppc_xics_enabled(vcpu))
		return;

	if (!xc)
		return;

	pr_devel("cleanup_vcpu(cpu=%d)\n", xc->server_num);

	/* Ensure no interrupt is still routed to that VP */
	xc->valid = false;
	kvmppc_xive_disable_vcpu_interrupts(vcpu);

	/* Mask the VP IPI */
	xive_vm_esb_load(&xc->vp_ipi_data, XIVE_ESB_SET_PQ_01);

	/* Free escalations */
	for (i = 0; i < KVMPPC_XIVE_Q_COUNT; i++) {
		if (xc->esc_virq[i]) {
			if (xc->xive->single_escalation)
				xive_cleanup_single_escalation(vcpu, xc,
							xc->esc_virq[i]);
			free_irq(xc->esc_virq[i], vcpu);
			irq_dispose_mapping(xc->esc_virq[i]);
			kfree(xc->esc_virq_names[i]);
		}
	}

	/* Disable the VP */
	xive_native_disable_vp(xc->vp_id);

	/* Clear the cam word so guest entry won't try to push context */
	vcpu->arch.xive_cam_word = 0;

	/* Free the queues */
	for (i = 0; i < KVMPPC_XIVE_Q_COUNT; i++) {
		struct xive_q *q = &xc->queues[i];

		xive_native_disable_queue(xc->vp_id, q, i);
		if (q->qpage) {
			free_pages((unsigned long)q->qpage,
				   xive->q_page_order);
			q->qpage = NULL;
		}
	}

	/* Free the IPI */
	if (xc->vp_ipi) {
		xive_cleanup_irq_data(&xc->vp_ipi_data);
		xive_native_free_irq(xc->vp_ipi);
	}
	/* Free the VP */
	kfree(xc);

	/* Cleanup the vcpu */
	vcpu->arch.irq_type = KVMPPC_IRQ_DEFAULT;
	vcpu->arch.xive_vcpu = NULL;
}