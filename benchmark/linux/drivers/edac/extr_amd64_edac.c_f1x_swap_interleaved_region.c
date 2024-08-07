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
typedef  int u64 ;
typedef  int u32 ;
struct amd64_pvt {int fam; int model; int stepping; int /*<<< orphan*/  F2; } ;

/* Variables and functions */
 int /*<<< orphan*/  SWAP_INTLV_REG ; 
 int /*<<< orphan*/  amd64_read_pci_cfg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static u64 f1x_swap_interleaved_region(struct amd64_pvt *pvt, u64 sys_addr)
{
	u32 swap_reg, swap_base, swap_limit, rgn_size, tmp_addr;

	if (pvt->fam == 0x10) {
		/* only revC3 and revE have that feature */
		if (pvt->model < 4 || (pvt->model < 0xa && pvt->stepping < 3))
			return sys_addr;
	}

	amd64_read_pci_cfg(pvt->F2, SWAP_INTLV_REG, &swap_reg);

	if (!(swap_reg & 0x1))
		return sys_addr;

	swap_base	= (swap_reg >> 3) & 0x7f;
	swap_limit	= (swap_reg >> 11) & 0x7f;
	rgn_size	= (swap_reg >> 20) & 0x7f;
	tmp_addr	= sys_addr >> 27;

	if (!(sys_addr >> 34) &&
	    (((tmp_addr >= swap_base) &&
	     (tmp_addr <= swap_limit)) ||
	     (tmp_addr < rgn_size)))
		return sys_addr ^ (u64)swap_base << 27;

	return sys_addr;
}