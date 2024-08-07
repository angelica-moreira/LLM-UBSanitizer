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
struct nfp_repr {TYPE_1__* netdev; } ;
struct nfp_app {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  mtu; } ;

/* Variables and functions */
 int /*<<< orphan*/  netif_tx_disable (TYPE_1__*) ; 
 int nfp_flower_cmsg_portmod (struct nfp_repr*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
nfp_flower_repr_netdev_stop(struct nfp_app *app, struct nfp_repr *repr)
{
	netif_tx_disable(repr->netdev);

	return nfp_flower_cmsg_portmod(repr, false, repr->netdev->mtu, false);
}