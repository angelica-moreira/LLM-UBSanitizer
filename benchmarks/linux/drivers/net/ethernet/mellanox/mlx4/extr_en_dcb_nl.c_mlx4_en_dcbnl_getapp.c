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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct net_device {int dummy; } ;
struct mlx4_en_priv {int dcbx_cap; } ;
struct dcb_app {int /*<<< orphan*/  protocol; int /*<<< orphan*/  selector; } ;

/* Variables and functions */
 int DCB_CAP_DCBX_VER_CEE ; 
 int dcb_getapp (struct net_device*,struct dcb_app*) ; 
 struct mlx4_en_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int mlx4_en_dcbnl_getapp(struct net_device *netdev, u8 idtype, u16 id)
{
	struct mlx4_en_priv *priv = netdev_priv(netdev);
	struct dcb_app app = {
				.selector = idtype,
				.protocol = id,
			     };
	if (!(priv->dcbx_cap & DCB_CAP_DCBX_VER_CEE))
		return 0;

	return dcb_getapp(netdev, &app);
}