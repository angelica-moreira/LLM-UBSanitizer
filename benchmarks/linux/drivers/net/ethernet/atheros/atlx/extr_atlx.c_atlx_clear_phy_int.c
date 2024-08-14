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
typedef  int /*<<< orphan*/  u16 ;
struct atlx_adapter {int /*<<< orphan*/  lock; int /*<<< orphan*/  hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  atlx_read_phy_reg (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void atlx_clear_phy_int(struct atlx_adapter *adapter)
{
	u16 phy_data;
	unsigned long flags;

	spin_lock_irqsave(&adapter->lock, flags);
	atlx_read_phy_reg(&adapter->hw, 19, &phy_data);
	spin_unlock_irqrestore(&adapter->lock, flags);
}