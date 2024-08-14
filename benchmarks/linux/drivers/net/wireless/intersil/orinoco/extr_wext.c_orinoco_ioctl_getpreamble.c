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
struct orinoco_private {int preamble; int /*<<< orphan*/  has_preamble; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 struct orinoco_private* ndev_priv (struct net_device*) ; 

__attribute__((used)) static int orinoco_ioctl_getpreamble(struct net_device *dev,
				     struct iw_request_info *info,
				     void *wrqu,
				     char *extra)
{
	struct orinoco_private *priv = ndev_priv(dev);
	int *val = (int *) extra;

	if (!priv->has_preamble)
		return -EOPNOTSUPP;

	*val = priv->preamble;
	return 0;
}