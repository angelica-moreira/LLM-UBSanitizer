#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct iw_point {int /*<<< orphan*/  length; } ;
struct TYPE_3__ {int /*<<< orphan*/  mib_sem; int /*<<< orphan*/  nickname; } ;
typedef  TYPE_1__ islpci_private ;

/* Variables and functions */
 int E2BIG ; 
 int /*<<< orphan*/  IW_ESSID_MAX_SIZE ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
prism54_set_nick(struct net_device *ndev, struct iw_request_info *info,
		 struct iw_point *dwrq, char *extra)
{
	islpci_private *priv = netdev_priv(ndev);

	if (dwrq->length > IW_ESSID_MAX_SIZE)
		return -E2BIG;

	down_write(&priv->mib_sem);
	memset(priv->nickname, 0, sizeof (priv->nickname));
	memcpy(priv->nickname, extra, dwrq->length);
	up_write(&priv->mib_sem);

	return 0;
}