#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct ath10k_hw_ce_dst_src_wm_regs {int addr; TYPE_2__* wm_high; } ;
struct ath10k {TYPE_1__* hw_ce_regs; } ;
struct TYPE_4__ {int mask; } ;
struct TYPE_3__ {struct ath10k_hw_ce_dst_src_wm_regs* wm_dstr; } ;

/* Variables and functions */
 int ath10k_ce_read32 (struct ath10k*,int) ; 
 int /*<<< orphan*/  ath10k_ce_write32 (struct ath10k*,int,int) ; 
 int ath10k_set_ring_byte (unsigned int,TYPE_2__*) ; 

__attribute__((used)) static inline void ath10k_ce_dest_ring_highmark_set(struct ath10k *ar,
						    u32 ce_ctrl_addr,
						    unsigned int n)
{
	struct ath10k_hw_ce_dst_src_wm_regs *dstr_wm = ar->hw_ce_regs->wm_dstr;
	u32 addr = ath10k_ce_read32(ar, ce_ctrl_addr + dstr_wm->addr);

	ath10k_ce_write32(ar, ce_ctrl_addr + dstr_wm->addr,
			  (addr & ~(dstr_wm->wm_high->mask)) |
			  (ath10k_set_ring_byte(n, dstr_wm->wm_high)));
}