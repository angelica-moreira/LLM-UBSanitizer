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
struct TYPE_2__ {int /*<<< orphan*/  fcccp; int /*<<< orphan*/  ep; int /*<<< orphan*/  fccp; } ;
struct fs_enet_private {TYPE_1__ fcc; } ;
typedef  int /*<<< orphan*/  fcc_t ;
typedef  int /*<<< orphan*/  fcc_enet_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  memcpy_fromio (void*,int /*<<< orphan*/ ,int) ; 
 struct fs_enet_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int get_regs(struct net_device *dev, void *p, int *sizep)
{
	struct fs_enet_private *fep = netdev_priv(dev);

	if (*sizep < sizeof(fcc_t) + sizeof(fcc_enet_t) + 1)
		return -EINVAL;

	memcpy_fromio(p, fep->fcc.fccp, sizeof(fcc_t));
	p = (char *)p + sizeof(fcc_t);

	memcpy_fromio(p, fep->fcc.ep, sizeof(fcc_enet_t));
	p = (char *)p + sizeof(fcc_enet_t);

	memcpy_fromio(p, fep->fcc.fcccp, 1);
	return 0;
}