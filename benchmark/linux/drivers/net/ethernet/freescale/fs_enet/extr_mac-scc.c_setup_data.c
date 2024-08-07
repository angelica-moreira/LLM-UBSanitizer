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
struct net_device {int dummy; } ;
struct TYPE_2__ {scalar_t__ htlo; scalar_t__ hthi; } ;
struct fs_enet_private {int ev; int /*<<< orphan*/  ev_err; int /*<<< orphan*/  ev_napi; TYPE_1__ scc; } ;

/* Variables and functions */
 int SCCE_ENET_TXE ; 
 int /*<<< orphan*/  SCC_ERR_EVENT_MSK ; 
 int SCC_EVENT ; 
 int /*<<< orphan*/  SCC_NAPI_EVENT_MSK ; 
 int /*<<< orphan*/  do_pd_setup (struct fs_enet_private*) ; 
 struct fs_enet_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int setup_data(struct net_device *dev)
{
	struct fs_enet_private *fep = netdev_priv(dev);

	do_pd_setup(fep);

	fep->scc.hthi = 0;
	fep->scc.htlo = 0;

	fep->ev_napi = SCC_NAPI_EVENT_MSK;
	fep->ev = SCC_EVENT | SCCE_ENET_TXE;
	fep->ev_err = SCC_ERR_EVENT_MSK;

	return 0;
}