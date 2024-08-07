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
struct ksz_hw {int enabled; } ;

/* Variables and functions */
 int /*<<< orphan*/  hw_start_rx (struct ksz_hw*) ; 
 int /*<<< orphan*/  hw_start_tx (struct ksz_hw*) ; 

__attribute__((used)) static void hw_enable(struct ksz_hw *hw)
{
	hw_start_tx(hw);
	hw_start_rx(hw);
	hw->enabled = 1;
}