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
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct atmel_private {int /*<<< orphan*/  operating_mode; } ;
typedef  int /*<<< orphan*/  __u32 ;

/* Variables and functions */
 struct atmel_private* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int atmel_get_mode(struct net_device *dev,
			  struct iw_request_info *info,
			  __u32 *uwrq,
			  char *extra)
{
	struct atmel_private *priv = netdev_priv(dev);

	*uwrq = priv->operating_mode;
	return 0;
}