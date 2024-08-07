#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_5__ {int /*<<< orphan*/  (* release_swfw_sync ) (struct ixgbe_hw*,int) ;scalar_t__ (* acquire_swfw_sync ) (struct ixgbe_hw*,int) ;} ;
struct TYPE_6__ {TYPE_1__ ops; } ;
struct TYPE_7__ {int /*<<< orphan*/  (* read_reg_mdi ) (struct ixgbe_hw*,int,int,int /*<<< orphan*/ *) ;} ;
struct TYPE_8__ {int phy_semaphore_mask; TYPE_3__ ops; } ;
struct ixgbe_hw {TYPE_2__ mac; TYPE_4__ phy; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  IXGBE_ERR_SWFW_SYNC ; 
 int IXGBE_GSSR_TOKEN_SM ; 
 scalar_t__ stub1 (struct ixgbe_hw*,int) ; 
 int /*<<< orphan*/  stub2 (struct ixgbe_hw*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub3 (struct ixgbe_hw*,int) ; 

__attribute__((used)) static s32 ixgbe_read_phy_reg_x550a(struct ixgbe_hw *hw, u32 reg_addr,
				    u32 device_type, u16 *phy_data)
{
	u32 mask = hw->phy.phy_semaphore_mask | IXGBE_GSSR_TOKEN_SM;
	s32 status;

	if (hw->mac.ops.acquire_swfw_sync(hw, mask))
		return IXGBE_ERR_SWFW_SYNC;

	status = hw->phy.ops.read_reg_mdi(hw, reg_addr, device_type, phy_data);

	hw->mac.ops.release_swfw_sync(hw, mask);

	return status;
}