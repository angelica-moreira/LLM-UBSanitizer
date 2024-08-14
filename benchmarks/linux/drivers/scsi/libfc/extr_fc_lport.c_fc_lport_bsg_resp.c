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
typedef  int /*<<< orphan*/  uint32_t ;
struct fc_seq {int dummy; } ;
struct fc_lport {int /*<<< orphan*/  lp_mutex; } ;
struct fc_frame_header {int /*<<< orphan*/  fh_f_ctl; int /*<<< orphan*/  fh_seq_cnt; } ;
struct fc_frame {int dummy; } ;
struct fc_ct_hdr {int /*<<< orphan*/  ct_cmd; } ;
struct TYPE_4__ {int /*<<< orphan*/  status; } ;
struct TYPE_5__ {TYPE_1__ ctels_reply; } ;
struct fc_bsg_reply {scalar_t__ reply_payload_rcv_len; scalar_t__ result; TYPE_2__ reply_data; } ;
struct fc_bsg_info {unsigned short rsp_code; int /*<<< orphan*/  offset; int /*<<< orphan*/  nents; int /*<<< orphan*/  sg; struct fc_lport* lport; struct bsg_job* job; } ;
struct TYPE_6__ {scalar_t__ payload_len; } ;
struct bsg_job {int reply_len; TYPE_3__ reply_payload; struct fc_bsg_reply* reply; } ;

/* Variables and functions */
 scalar_t__ ECONNABORTED ; 
 scalar_t__ ETIMEDOUT ; 
 int /*<<< orphan*/  FC_CTELS_STATUS_OK ; 
 int /*<<< orphan*/  FC_CTELS_STATUS_REJECT ; 
 scalar_t__ FC_EOF_T ; 
 int /*<<< orphan*/  FC_EX_CLOSED ; 
 int FC_FC_END_SEQ ; 
 int FC_FC_LAST_SEQ ; 
 unsigned short FC_FS_ACC ; 
 scalar_t__ FC_SOF_I3 ; 
 scalar_t__ IS_ERR (struct fc_frame*) ; 
 int /*<<< orphan*/  PTR_ERR (struct fc_frame*) ; 
 int /*<<< orphan*/  bsg_job_done (struct bsg_job*,scalar_t__,scalar_t__) ; 
 scalar_t__ fc_copy_buffer_to_sglist (void*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fc_frame_free (struct fc_frame*) ; 
 struct fc_frame_header* fc_frame_header_get (struct fc_frame*) ; 
 void* fc_frame_payload_get (struct fc_frame*,int /*<<< orphan*/ ) ; 
 scalar_t__ fc_frame_payload_op (struct fc_frame*) ; 
 scalar_t__ fr_eof (struct fc_frame*) ; 
 int fr_len (struct fc_frame*) ; 
 scalar_t__ fr_sof (struct fc_frame*) ; 
 int /*<<< orphan*/  kfree (struct fc_bsg_info*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int ntoh24 (int /*<<< orphan*/ ) ; 
 unsigned short ntohs (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fc_lport_bsg_resp(struct fc_seq *sp, struct fc_frame *fp,
			      void *info_arg)
{
	struct fc_bsg_info *info = info_arg;
	struct bsg_job *job = info->job;
	struct fc_bsg_reply *bsg_reply = job->reply;
	struct fc_lport *lport = info->lport;
	struct fc_frame_header *fh;
	size_t len;
	void *buf;

	if (IS_ERR(fp)) {
		bsg_reply->result = (PTR_ERR(fp) == -FC_EX_CLOSED) ?
			-ECONNABORTED : -ETIMEDOUT;
		job->reply_len = sizeof(uint32_t);
		bsg_job_done(job, bsg_reply->result,
			       bsg_reply->reply_payload_rcv_len);
		kfree(info);
		return;
	}

	mutex_lock(&lport->lp_mutex);
	fh = fc_frame_header_get(fp);
	len = fr_len(fp) - sizeof(*fh);
	buf = fc_frame_payload_get(fp, 0);

	if (fr_sof(fp) == FC_SOF_I3 && !ntohs(fh->fh_seq_cnt)) {
		/* Get the response code from the first frame payload */
		unsigned short cmd = (info->rsp_code == FC_FS_ACC) ?
			ntohs(((struct fc_ct_hdr *)buf)->ct_cmd) :
			(unsigned short)fc_frame_payload_op(fp);

		/* Save the reply status of the job */
		bsg_reply->reply_data.ctels_reply.status =
			(cmd == info->rsp_code) ?
			FC_CTELS_STATUS_OK : FC_CTELS_STATUS_REJECT;
	}

	bsg_reply->reply_payload_rcv_len +=
		fc_copy_buffer_to_sglist(buf, len, info->sg, &info->nents,
					 &info->offset, NULL);

	if (fr_eof(fp) == FC_EOF_T &&
	    (ntoh24(fh->fh_f_ctl) & (FC_FC_LAST_SEQ | FC_FC_END_SEQ)) ==
	    (FC_FC_LAST_SEQ | FC_FC_END_SEQ)) {
		if (bsg_reply->reply_payload_rcv_len >
		    job->reply_payload.payload_len)
			bsg_reply->reply_payload_rcv_len =
				job->reply_payload.payload_len;
		bsg_reply->result = 0;
		bsg_job_done(job, bsg_reply->result,
			       bsg_reply->reply_payload_rcv_len);
		kfree(info);
	}
	fc_frame_free(fp);
	mutex_unlock(&lport->lp_mutex);
}