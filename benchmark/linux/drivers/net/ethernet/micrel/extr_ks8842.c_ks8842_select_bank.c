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
struct ks8842_adapter {scalar_t__ hw_addr; } ;

/* Variables and functions */
 scalar_t__ REG_SELECT_BANK ; 
 int /*<<< orphan*/  iowrite16 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void ks8842_select_bank(struct ks8842_adapter *adapter, u16 bank)
{
	iowrite16(bank, adapter->hw_addr + REG_SELECT_BANK);
}