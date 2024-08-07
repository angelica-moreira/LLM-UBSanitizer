#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_9__ ;
typedef  struct TYPE_26__   TYPE_8__ ;
typedef  struct TYPE_25__   TYPE_7__ ;
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct qla_mt_iocb_rqst_fx00 {int flags; int /*<<< orphan*/  func_type; int /*<<< orphan*/  dataword; } ;
struct qla_hw_data {TYPE_6__* pdev; int /*<<< orphan*/  srb_mempool; } ;
struct fc_port {int /*<<< orphan*/  loop_id; TYPE_9__* vha; } ;
struct TYPE_19__ {int /*<<< orphan*/ * vendor_cmd; } ;
struct TYPE_20__ {TYPE_1__ h_vendor; } ;
struct fc_bsg_request {TYPE_2__ rqst_data; } ;
struct TYPE_25__ {int /*<<< orphan*/  sg_cnt; int /*<<< orphan*/  sg_list; } ;
struct TYPE_23__ {int /*<<< orphan*/  sg_cnt; int /*<<< orphan*/  sg_list; } ;
struct bsg_job {TYPE_7__ request_payload; TYPE_5__ reply_payload; struct fc_bsg_request* request; } ;
struct Scsi_Host {int dummy; } ;
struct TYPE_22__ {struct bsg_job* bsg_job; } ;
struct TYPE_26__ {char* name; int /*<<< orphan*/  done; int /*<<< orphan*/  free; TYPE_4__ u; int /*<<< orphan*/  iocbs; int /*<<< orphan*/  type; } ;
typedef  TYPE_8__ srb_t ;
struct TYPE_21__ {int /*<<< orphan*/  online; } ;
struct TYPE_27__ {TYPE_3__ flags; struct qla_hw_data* hw; } ;
typedef  TYPE_9__ scsi_qla_host_t ;
struct TYPE_24__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int DID_ERROR ; 
 int /*<<< orphan*/  DMA_FROM_DEVICE ; 
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int QLA_SUCCESS ; 
 int SRB_FXDISC_REQ_DMA_VALID ; 
 int SRB_FXDISC_RESP_DMA_VALID ; 
 int /*<<< orphan*/  SRB_FXIOCB_BCMD ; 
 int dma_map_sg (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_unmap_sg (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct Scsi_Host* fc_bsg_to_shost (struct bsg_job*) ; 
 int /*<<< orphan*/  kfree (struct fc_port*) ; 
 int /*<<< orphan*/  mempool_free (TYPE_8__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ql_dbg (scalar_t__,TYPE_9__*,int,char*,char*,int,int /*<<< orphan*/ ,...) ; 
 scalar_t__ ql_dbg_user ; 
 scalar_t__ ql_dbg_verbose ; 
 int /*<<< orphan*/  ql_dump_buffer (scalar_t__,TYPE_9__*,int,struct qla_mt_iocb_rqst_fx00*,int) ; 
 int /*<<< orphan*/  ql_log (int /*<<< orphan*/ ,TYPE_9__*,int,char*,...) ; 
 int /*<<< orphan*/  ql_log_warn ; 
 int /*<<< orphan*/  qla24xx_calc_ct_iocbs (int) ; 
 struct fc_port* qla2x00_alloc_fcport (TYPE_9__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qla2x00_bsg_job_done ; 
 int /*<<< orphan*/  qla2x00_bsg_sp_free ; 
 TYPE_8__* qla2x00_get_sp (TYPE_9__*,struct fc_port*,int /*<<< orphan*/ ) ; 
 int qla2x00_start_sp (TYPE_8__*) ; 
 TYPE_9__* shost_priv (struct Scsi_Host*) ; 

__attribute__((used)) static int
qlafx00_mgmt_cmd(struct bsg_job *bsg_job)
{
	struct fc_bsg_request *bsg_request = bsg_job->request;
	struct Scsi_Host *host = fc_bsg_to_shost(bsg_job);
	scsi_qla_host_t *vha = shost_priv(host);
	struct qla_hw_data *ha = vha->hw;
	int rval = (DID_ERROR << 16);
	struct qla_mt_iocb_rqst_fx00 *piocb_rqst;
	srb_t *sp;
	int req_sg_cnt = 0, rsp_sg_cnt = 0;
	struct fc_port *fcport;
	char  *type = "FC_BSG_HST_FX_MGMT";

	/* Copy the IOCB specific information */
	piocb_rqst = (struct qla_mt_iocb_rqst_fx00 *)
	    &bsg_request->rqst_data.h_vendor.vendor_cmd[1];

	/* Dump the vendor information */
	ql_dump_buffer(ql_dbg_user + ql_dbg_verbose , vha, 0x70cf,
	    piocb_rqst, sizeof(*piocb_rqst));

	if (!vha->flags.online) {
		ql_log(ql_log_warn, vha, 0x70d0,
		    "Host is not online.\n");
		rval = -EIO;
		goto done;
	}

	if (piocb_rqst->flags & SRB_FXDISC_REQ_DMA_VALID) {
		req_sg_cnt = dma_map_sg(&ha->pdev->dev,
		    bsg_job->request_payload.sg_list,
		    bsg_job->request_payload.sg_cnt, DMA_TO_DEVICE);
		if (!req_sg_cnt) {
			ql_log(ql_log_warn, vha, 0x70c7,
			    "dma_map_sg return %d for request\n", req_sg_cnt);
			rval = -ENOMEM;
			goto done;
		}
	}

	if (piocb_rqst->flags & SRB_FXDISC_RESP_DMA_VALID) {
		rsp_sg_cnt = dma_map_sg(&ha->pdev->dev,
		    bsg_job->reply_payload.sg_list,
		    bsg_job->reply_payload.sg_cnt, DMA_FROM_DEVICE);
		if (!rsp_sg_cnt) {
			ql_log(ql_log_warn, vha, 0x70c8,
			    "dma_map_sg return %d for reply\n", rsp_sg_cnt);
			rval = -ENOMEM;
			goto done_unmap_req_sg;
		}
	}

	ql_dbg(ql_dbg_user, vha, 0x70c9,
	    "request_sg_cnt: %x dma_request_sg_cnt: %x reply_sg_cnt:%x "
	    "dma_reply_sg_cnt: %x\n", bsg_job->request_payload.sg_cnt,
	    req_sg_cnt, bsg_job->reply_payload.sg_cnt, rsp_sg_cnt);

	/* Allocate a dummy fcport structure, since functions preparing the
	 * IOCB and mailbox command retrieves port specific information
	 * from fcport structure. For Host based ELS commands there will be
	 * no fcport structure allocated
	 */
	fcport = qla2x00_alloc_fcport(vha, GFP_KERNEL);
	if (!fcport) {
		ql_log(ql_log_warn, vha, 0x70ca,
		    "Failed to allocate fcport.\n");
		rval = -ENOMEM;
		goto done_unmap_rsp_sg;
	}

	/* Alloc SRB structure */
	sp = qla2x00_get_sp(vha, fcport, GFP_KERNEL);
	if (!sp) {
		ql_log(ql_log_warn, vha, 0x70cb,
		    "qla2x00_get_sp failed.\n");
		rval = -ENOMEM;
		goto done_free_fcport;
	}

	/* Initialize all required  fields of fcport */
	fcport->vha = vha;
	fcport->loop_id = piocb_rqst->dataword;

	sp->type = SRB_FXIOCB_BCMD;
	sp->name = "bsg_fx_mgmt";
	sp->iocbs = qla24xx_calc_ct_iocbs(req_sg_cnt + rsp_sg_cnt);
	sp->u.bsg_job = bsg_job;
	sp->free = qla2x00_bsg_sp_free;
	sp->done = qla2x00_bsg_job_done;

	ql_dbg(ql_dbg_user, vha, 0x70cc,
	    "bsg rqst type: %s fx_mgmt_type: %x id=%x\n",
	    type, piocb_rqst->func_type, fcport->loop_id);

	rval = qla2x00_start_sp(sp);
	if (rval != QLA_SUCCESS) {
		ql_log(ql_log_warn, vha, 0x70cd,
		    "qla2x00_start_sp failed=%d.\n", rval);
		mempool_free(sp, ha->srb_mempool);
		rval = -EIO;
		goto done_free_fcport;
	}
	return rval;

done_free_fcport:
	kfree(fcport);

done_unmap_rsp_sg:
	if (piocb_rqst->flags & SRB_FXDISC_RESP_DMA_VALID)
		dma_unmap_sg(&ha->pdev->dev,
		    bsg_job->reply_payload.sg_list,
		    bsg_job->reply_payload.sg_cnt, DMA_FROM_DEVICE);
done_unmap_req_sg:
	if (piocb_rqst->flags & SRB_FXDISC_REQ_DMA_VALID)
		dma_unmap_sg(&ha->pdev->dev,
		    bsg_job->request_payload.sg_list,
		    bsg_job->request_payload.sg_cnt, DMA_TO_DEVICE);

done:
	return rval;
}