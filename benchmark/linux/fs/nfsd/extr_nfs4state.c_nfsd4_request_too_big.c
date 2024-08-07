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
struct xdr_buf {scalar_t__ len; } ;
struct svc_rqst {struct xdr_buf rq_arg; } ;
struct TYPE_2__ {scalar_t__ maxreq_sz; } ;
struct nfsd4_session {TYPE_1__ se_fchannel; } ;

/* Variables and functions */

__attribute__((used)) static bool nfsd4_request_too_big(struct svc_rqst *rqstp,
				  struct nfsd4_session *session)
{
	struct xdr_buf *xb = &rqstp->rq_arg;

	return xb->len > session->se_fchannel.maxreq_sz;
}