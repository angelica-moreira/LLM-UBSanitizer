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
struct iscsi_endpoint {struct cxgbi_endpoint* dd_data; } ;
struct cxgbi_sock {int dummy; } ;
struct cxgbi_endpoint {struct cxgbi_sock* csk; } ;

/* Variables and functions */
 int /*<<< orphan*/  cxgbi_sock_is_established (struct cxgbi_sock*) ; 

int cxgbi_ep_poll(struct iscsi_endpoint *ep, int timeout_ms)
{
	struct cxgbi_endpoint *cep = ep->dd_data;
	struct cxgbi_sock *csk = cep->csk;

	if (!cxgbi_sock_is_established(csk))
		return 0;
	return 1;
}