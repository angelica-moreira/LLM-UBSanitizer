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
struct TYPE_5__ {int /*<<< orphan*/  (* check_link ) (struct ixgbe_hw*,int*,int*,int) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  type; TYPE_1__ ops; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* check_overtemp ) (struct ixgbe_hw*) ;} ;
struct TYPE_7__ {TYPE_2__ ops; } ;
struct ixgbe_hw {int device_id; TYPE_4__ mac; TYPE_3__ phy; } ;
struct ixgbe_adapter {int interrupt_event; int flags2; struct ixgbe_hw hw; int /*<<< orphan*/  state; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
#define  IXGBE_DEV_ID_82599_T3_LOM 130 
#define  IXGBE_DEV_ID_X550EM_A_1G_T 129 
#define  IXGBE_DEV_ID_X550EM_A_1G_T_L 128 
 int IXGBE_EICR_GPI_SDP0 (struct ixgbe_hw*) ; 
 int IXGBE_EICR_GPI_SDP0_8259X ; 
 int IXGBE_EICR_LSC ; 
 int /*<<< orphan*/  IXGBE_ERR_OVERTEMP ; 
 int IXGBE_FLAG2_TEMP_SENSOR_EVENT ; 
 int /*<<< orphan*/  __IXGBE_DOWN ; 
 int /*<<< orphan*/  drv ; 
 int /*<<< orphan*/  e_crit (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ixgbe_mac_X540 ; 
 int /*<<< orphan*/  ixgbe_overheat_msg ; 
 int /*<<< orphan*/  stub1 (struct ixgbe_hw*,int*,int*,int) ; 
 int /*<<< orphan*/  stub2 (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  stub3 (struct ixgbe_hw*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ixgbe_check_overtemp_subtask(struct ixgbe_adapter *adapter)
{
	struct ixgbe_hw *hw = &adapter->hw;
	u32 eicr = adapter->interrupt_event;
	s32 rc;

	if (test_bit(__IXGBE_DOWN, &adapter->state))
		return;

	if (!(adapter->flags2 & IXGBE_FLAG2_TEMP_SENSOR_EVENT))
		return;

	adapter->flags2 &= ~IXGBE_FLAG2_TEMP_SENSOR_EVENT;

	switch (hw->device_id) {
	case IXGBE_DEV_ID_82599_T3_LOM:
		/*
		 * Since the warning interrupt is for both ports
		 * we don't have to check if:
		 *  - This interrupt wasn't for our port.
		 *  - We may have missed the interrupt so always have to
		 *    check if we  got a LSC
		 */
		if (!(eicr & IXGBE_EICR_GPI_SDP0_8259X) &&
		    !(eicr & IXGBE_EICR_LSC))
			return;

		if (!(eicr & IXGBE_EICR_LSC) && hw->mac.ops.check_link) {
			u32 speed;
			bool link_up = false;

			hw->mac.ops.check_link(hw, &speed, &link_up, false);

			if (link_up)
				return;
		}

		/* Check if this is not due to overtemp */
		if (hw->phy.ops.check_overtemp(hw) != IXGBE_ERR_OVERTEMP)
			return;

		break;
	case IXGBE_DEV_ID_X550EM_A_1G_T:
	case IXGBE_DEV_ID_X550EM_A_1G_T_L:
		rc = hw->phy.ops.check_overtemp(hw);
		if (rc != IXGBE_ERR_OVERTEMP)
			return;
		break;
	default:
		if (adapter->hw.mac.type >= ixgbe_mac_X540)
			return;
		if (!(eicr & IXGBE_EICR_GPI_SDP0(hw)))
			return;
		break;
	}
	e_crit(drv, "%s\n", ixgbe_overheat_msg);

	adapter->interrupt_event = 0;
}