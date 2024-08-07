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
struct ixgbevf_adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ixgbevf_down (struct ixgbevf_adapter*) ; 
 int /*<<< orphan*/  ixgbevf_free_all_rx_resources (struct ixgbevf_adapter*) ; 
 int /*<<< orphan*/  ixgbevf_free_all_tx_resources (struct ixgbevf_adapter*) ; 
 int /*<<< orphan*/  ixgbevf_free_irq (struct ixgbevf_adapter*) ; 

__attribute__((used)) static void ixgbevf_close_suspend(struct ixgbevf_adapter *adapter)
{
	ixgbevf_down(adapter);
	ixgbevf_free_irq(adapter);
	ixgbevf_free_all_tx_resources(adapter);
	ixgbevf_free_all_rx_resources(adapter);
}