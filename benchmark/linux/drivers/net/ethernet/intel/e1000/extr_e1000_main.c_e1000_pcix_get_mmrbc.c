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
struct e1000_hw {struct e1000_adapter* back; } ;
struct e1000_adapter {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int pcix_get_mmrbc (int /*<<< orphan*/ ) ; 

int e1000_pcix_get_mmrbc(struct e1000_hw *hw)
{
	struct e1000_adapter *adapter = hw->back;
	return pcix_get_mmrbc(adapter->pdev);
}