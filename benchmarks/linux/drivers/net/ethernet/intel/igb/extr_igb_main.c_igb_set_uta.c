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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int uta_reg_count; } ;
struct e1000_hw {TYPE_1__ mac; } ;
struct igb_adapter {int /*<<< orphan*/  vfs_allocated_count; struct e1000_hw hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  E1000_UTA ; 
 int /*<<< orphan*/  array_wr32 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void igb_set_uta(struct igb_adapter *adapter, bool set)
{
	struct e1000_hw *hw = &adapter->hw;
	u32 uta = set ? ~0 : 0;
	int i;

	/* we only need to do this if VMDq is enabled */
	if (!adapter->vfs_allocated_count)
		return;

	for (i = hw->mac.uta_reg_count; i--;)
		array_wr32(E1000_UTA, i, uta);
}