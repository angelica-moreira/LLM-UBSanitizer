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
typedef  unsigned long phys_addr_t ;

/* Variables and functions */
 unsigned int ARC_REG_DC_FLDL ; 
 unsigned int ARC_REG_DC_IVDL ; 
 unsigned int ARC_REG_DC_PTAG ; 
 unsigned int ARC_REG_IC_IVIL ; 
 unsigned int ARC_REG_IC_PTAG ; 
 unsigned int ARC_REG_IC_PTAG_HI ; 
 unsigned long CACHE_LINE_MASK ; 
 int DIV_ROUND_UP (unsigned long,scalar_t__) ; 
 scalar_t__ L1_CACHE_BYTES ; 
 int const OP_INV ; 
 int const OP_INV_IC ; 
 scalar_t__ is_pae40_enabled () ; 
 int /*<<< orphan*/  write_aux_reg (unsigned int,unsigned long) ; 

__attribute__((used)) static inline
void __cache_line_loop_v3(phys_addr_t paddr, unsigned long vaddr,
			  unsigned long sz, const int op, const int full_page)
{
	unsigned int aux_cmd, aux_tag;
	int num_lines;

	if (op == OP_INV_IC) {
		aux_cmd = ARC_REG_IC_IVIL;
		aux_tag = ARC_REG_IC_PTAG;
	} else {
		aux_cmd = op & OP_INV ? ARC_REG_DC_IVDL : ARC_REG_DC_FLDL;
		aux_tag = ARC_REG_DC_PTAG;
	}

	/* Ensure we properly floor/ceil the non-line aligned/sized requests
	 * and have @paddr - aligned to cache line and integral @num_lines.
	 * This however can be avoided for page sized since:
	 *  -@paddr will be cache-line aligned already (being page aligned)
	 *  -@sz will be integral multiple of line size (being page sized).
	 */
	if (!full_page) {
		sz += paddr & ~CACHE_LINE_MASK;
		paddr &= CACHE_LINE_MASK;
		vaddr &= CACHE_LINE_MASK;
	}
	num_lines = DIV_ROUND_UP(sz, L1_CACHE_BYTES);

	/*
	 * MMUv3, cache ops require paddr in PTAG reg
	 * if V-P const for loop, PTAG can be written once outside loop
	 */
	if (full_page)
		write_aux_reg(aux_tag, paddr);

	/*
	 * This is technically for MMU v4, using the MMU v3 programming model
	 * Special work for HS38 aliasing I-cache configuration with PAE40
	 *   - upper 8 bits of paddr need to be written into PTAG_HI
	 *   - (and needs to be written before the lower 32 bits)
	 * Note that PTAG_HI is hoisted outside the line loop
	 */
	if (is_pae40_enabled() && op == OP_INV_IC)
		write_aux_reg(ARC_REG_IC_PTAG_HI, (u64)paddr >> 32);

	while (num_lines-- > 0) {
		if (!full_page) {
			write_aux_reg(aux_tag, paddr);
			paddr += L1_CACHE_BYTES;
		}

		write_aux_reg(aux_cmd, vaddr);
		vaddr += L1_CACHE_BYTES;
	}
}