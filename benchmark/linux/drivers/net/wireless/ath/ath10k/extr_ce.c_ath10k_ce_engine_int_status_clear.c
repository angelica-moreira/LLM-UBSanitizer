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
typedef  scalar_t__ u32 ;
struct ath10k_hw_ce_host_wm_regs {scalar_t__ addr; } ;
struct ath10k {TYPE_1__* hw_ce_regs; } ;
struct TYPE_2__ {struct ath10k_hw_ce_host_wm_regs* wm_regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath10k_ce_write32 (struct ath10k*,scalar_t__,unsigned int) ; 

__attribute__((used)) static inline void ath10k_ce_engine_int_status_clear(struct ath10k *ar,
						     u32 ce_ctrl_addr,
						     unsigned int mask)
{
	struct ath10k_hw_ce_host_wm_regs *wm_regs = ar->hw_ce_regs->wm_regs;

	ath10k_ce_write32(ar, ce_ctrl_addr + wm_regs->addr, mask);
}