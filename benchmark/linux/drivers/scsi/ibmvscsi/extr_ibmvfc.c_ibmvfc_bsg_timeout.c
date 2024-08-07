#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  length; void* opcode; void* version; } ;
struct ibmvfc_tmf {void* my_cancel_key; void* cancel_key; int /*<<< orphan*/  scsi_id; TYPE_2__ common; } ;
struct ibmvfc_host {int aborting_passthru; scalar_t__ state; TYPE_3__* host; int /*<<< orphan*/  dev; } ;
struct TYPE_4__ {struct ibmvfc_tmf tmf; } ;
struct ibmvfc_event {TYPE_1__ iu; } ;
struct bsg_job {scalar_t__ dd_data; } ;
struct TYPE_6__ {int /*<<< orphan*/  host_lock; } ;

/* Variables and functions */
 int EIO ; 
 int /*<<< orphan*/  ENTER ; 
 scalar_t__ IBMVFC_ACTIVE ; 
 int IBMVFC_INTERNAL_CANCEL_KEY ; 
 int /*<<< orphan*/  IBMVFC_MAD_FORMAT ; 
 int IBMVFC_PASSTHRU_CANCEL_KEY ; 
 int IBMVFC_TMF_MAD ; 
 int /*<<< orphan*/  LEAVE ; 
 int /*<<< orphan*/  __ibmvfc_reset_host (struct ibmvfc_host*) ; 
 int /*<<< orphan*/  cpu_to_be16 (int) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  cpu_to_be64 (unsigned long) ; 
 int /*<<< orphan*/  default_timeout ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,unsigned long) ; 
 int /*<<< orphan*/  fc_bsg_to_shost (struct bsg_job*) ; 
 int /*<<< orphan*/  ibmvfc_bsg_timeout_done ; 
 struct ibmvfc_event* ibmvfc_get_event (struct ibmvfc_host*) ; 
 int /*<<< orphan*/  ibmvfc_init_event (struct ibmvfc_event*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int ibmvfc_send_event (struct ibmvfc_event*,struct ibmvfc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct ibmvfc_tmf*,int /*<<< orphan*/ ,int) ; 
 struct ibmvfc_host* shost_priv (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static int ibmvfc_bsg_timeout(struct bsg_job *job)
{
	struct ibmvfc_host *vhost = shost_priv(fc_bsg_to_shost(job));
	unsigned long port_id = (unsigned long)job->dd_data;
	struct ibmvfc_event *evt;
	struct ibmvfc_tmf *tmf;
	unsigned long flags;
	int rc;

	ENTER;
	spin_lock_irqsave(vhost->host->host_lock, flags);
	if (vhost->aborting_passthru || vhost->state != IBMVFC_ACTIVE) {
		__ibmvfc_reset_host(vhost);
		spin_unlock_irqrestore(vhost->host->host_lock, flags);
		return 0;
	}

	vhost->aborting_passthru = 1;
	evt = ibmvfc_get_event(vhost);
	ibmvfc_init_event(evt, ibmvfc_bsg_timeout_done, IBMVFC_MAD_FORMAT);

	tmf = &evt->iu.tmf;
	memset(tmf, 0, sizeof(*tmf));
	tmf->common.version = cpu_to_be32(1);
	tmf->common.opcode = cpu_to_be32(IBMVFC_TMF_MAD);
	tmf->common.length = cpu_to_be16(sizeof(*tmf));
	tmf->scsi_id = cpu_to_be64(port_id);
	tmf->cancel_key = cpu_to_be32(IBMVFC_PASSTHRU_CANCEL_KEY);
	tmf->my_cancel_key = cpu_to_be32(IBMVFC_INTERNAL_CANCEL_KEY);
	rc = ibmvfc_send_event(evt, vhost, default_timeout);

	if (rc != 0) {
		vhost->aborting_passthru = 0;
		dev_err(vhost->dev, "Failed to send cancel event. rc=%d\n", rc);
		rc = -EIO;
	} else
		dev_info(vhost->dev, "Cancelling passthru command to port id 0x%lx\n",
			 port_id);

	spin_unlock_irqrestore(vhost->host->host_lock, flags);

	LEAVE;
	return rc;
}