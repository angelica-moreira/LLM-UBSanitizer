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
typedef  int /*<<< orphan*/  u32 ;
struct nfp_net {int dummy; } ;

/* Variables and functions */
 int __nfp_net_reconfig (struct nfp_net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nn_ctrl_bar_lock (struct nfp_net*) ; 
 int /*<<< orphan*/  nn_ctrl_bar_unlock (struct nfp_net*) ; 

int nfp_net_reconfig(struct nfp_net *nn, u32 update)
{
	int ret;

	nn_ctrl_bar_lock(nn);
	ret = __nfp_net_reconfig(nn, update);
	nn_ctrl_bar_unlock(nn);

	return ret;
}