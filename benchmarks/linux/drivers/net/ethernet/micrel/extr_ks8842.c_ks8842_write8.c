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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct ks8842_adapter {scalar_t__ hw_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite8 (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ks8842_select_bank (struct ks8842_adapter*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void ks8842_write8(struct ks8842_adapter *adapter, u16 bank,
	u8 value, int offset)
{
	ks8842_select_bank(adapter, bank);
	iowrite8(value, adapter->hw_addr + offset);
}