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
typedef  int u32 ;
struct ixgbe_hw {int dummy; } ;

/* Variables and functions */
 int ixgbevf_read_reg (struct ixgbe_hw*,int) ; 

__attribute__((used)) static inline u32 ixgbe_read_reg_array(struct ixgbe_hw *hw, u32 reg,
				       u32 offset)
{
	return ixgbevf_read_reg(hw, reg + (offset << 2));
}