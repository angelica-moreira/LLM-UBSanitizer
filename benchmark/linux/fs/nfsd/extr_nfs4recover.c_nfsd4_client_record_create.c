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
struct nfsd_net {TYPE_1__* client_tracking_ops; } ;
struct nfs4_client {int /*<<< orphan*/  net; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* create ) (struct nfs4_client*) ;} ;

/* Variables and functions */
 struct nfsd_net* net_generic (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfsd_net_id ; 
 int /*<<< orphan*/  stub1 (struct nfs4_client*) ; 

void
nfsd4_client_record_create(struct nfs4_client *clp)
{
	struct nfsd_net *nn = net_generic(clp->net, nfsd_net_id);

	if (nn->client_tracking_ops)
		nn->client_tracking_ops->create(clp);
}