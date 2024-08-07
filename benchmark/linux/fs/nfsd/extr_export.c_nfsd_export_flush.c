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
struct nfsd_net {int /*<<< orphan*/  svc_export_cache; int /*<<< orphan*/  svc_expkey_cache; } ;
struct net {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cache_purge (int /*<<< orphan*/ ) ; 
 struct nfsd_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfsd_net_id ; 

void
nfsd_export_flush(struct net *net)
{
	struct nfsd_net *nn = net_generic(net, nfsd_net_id);

	cache_purge(nn->svc_expkey_cache);
	cache_purge(nn->svc_export_cache);
}