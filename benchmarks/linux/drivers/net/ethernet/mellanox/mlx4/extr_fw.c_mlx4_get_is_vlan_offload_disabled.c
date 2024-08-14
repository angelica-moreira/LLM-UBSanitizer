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
struct mlx4_func_cap {int flags0; } ;
struct mlx4_dev {int dummy; } ;
typedef  int /*<<< orphan*/  func_cap ;

/* Variables and functions */
 int QUERY_FUNC_CAP_VLAN_OFFLOAD_DISABLE ; 
 int /*<<< orphan*/  memset (struct mlx4_func_cap*,int /*<<< orphan*/ ,int) ; 
 int mlx4_QUERY_FUNC_CAP (struct mlx4_dev*,int /*<<< orphan*/ ,struct mlx4_func_cap*) ; 

int mlx4_get_is_vlan_offload_disabled(struct mlx4_dev *dev, u8 port,
				      bool *vlan_offload_disabled)
{
	struct mlx4_func_cap func_cap;
	int err;

	memset(&func_cap, 0, sizeof(func_cap));
	err = mlx4_QUERY_FUNC_CAP(dev, port, &func_cap);
	if (!err)
		*vlan_offload_disabled =
			!!(func_cap.flags0 &
			   QUERY_FUNC_CAP_VLAN_OFFLOAD_DISABLE);
	return err;
}