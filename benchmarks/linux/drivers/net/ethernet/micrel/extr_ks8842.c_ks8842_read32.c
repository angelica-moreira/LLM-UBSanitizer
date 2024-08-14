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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ks8842_adapter {scalar_t__ hw_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  ks8842_select_bank (struct ks8842_adapter*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 ks8842_read32(struct ks8842_adapter *adapter, u16 bank,
	int offset)
{
	ks8842_select_bank(adapter, bank);
	return ioread32(adapter->hw_addr + offset);
}