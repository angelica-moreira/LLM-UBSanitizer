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
struct smb_rqst {int rq_nvec; struct kvec* rq_iov; } ;
struct mid_q_entry {unsigned int resp_buf_size; scalar_t__ resp_buf; int /*<<< orphan*/  decrypted; } ;
struct kvec {char* iov_base; unsigned int iov_len; } ;
struct TCP_Server_Info {scalar_t__ sign; } ;

/* Variables and functions */
 int /*<<< orphan*/  VFS ; 
 int /*<<< orphan*/  cifs_server_dbg (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dump_smb (scalar_t__,int /*<<< orphan*/ ) ; 
 int map_smb2_to_linux_error (scalar_t__,int) ; 
 int /*<<< orphan*/  min_t (int /*<<< orphan*/ ,int,unsigned int) ; 
 int smb2_verify_signature (struct smb_rqst*,struct TCP_Server_Info*) ; 
 int /*<<< orphan*/  u32 ; 

int
smb2_check_receive(struct mid_q_entry *mid, struct TCP_Server_Info *server,
		   bool log_error)
{
	unsigned int len = mid->resp_buf_size;
	struct kvec iov[1];
	struct smb_rqst rqst = { .rq_iov = iov,
				 .rq_nvec = 1 };

	iov[0].iov_base = (char *)mid->resp_buf;
	iov[0].iov_len = len;

	dump_smb(mid->resp_buf, min_t(u32, 80, len));
	/* convert the length into a more usable form */
	if (len > 24 && server->sign && !mid->decrypted) {
		int rc;

		rc = smb2_verify_signature(&rqst, server);
		if (rc)
			cifs_server_dbg(VFS, "SMB signature verification returned error = %d\n",
				 rc);
	}

	return map_smb2_to_linux_error(mid->resp_buf, log_error);
}