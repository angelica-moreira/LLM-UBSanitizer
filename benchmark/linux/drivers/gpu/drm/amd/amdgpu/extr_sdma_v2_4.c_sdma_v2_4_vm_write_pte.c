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
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
struct amdgpu_ib {int* ptr; int /*<<< orphan*/  length_dw; } ;

/* Variables and functions */
 int /*<<< orphan*/  SDMA_OP_WRITE ; 
 int SDMA_PKT_HEADER_OP (int /*<<< orphan*/ ) ; 
 int SDMA_PKT_HEADER_SUB_OP (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDMA_SUBOP_WRITE_LINEAR ; 
 unsigned int lower_32_bits (int) ; 
 void* upper_32_bits (int) ; 

__attribute__((used)) static void sdma_v2_4_vm_write_pte(struct amdgpu_ib *ib, uint64_t pe,
				   uint64_t value, unsigned count,
				   uint32_t incr)
{
	unsigned ndw = count * 2;

	ib->ptr[ib->length_dw++] = SDMA_PKT_HEADER_OP(SDMA_OP_WRITE) |
		SDMA_PKT_HEADER_SUB_OP(SDMA_SUBOP_WRITE_LINEAR);
	ib->ptr[ib->length_dw++] = pe;
	ib->ptr[ib->length_dw++] = upper_32_bits(pe);
	ib->ptr[ib->length_dw++] = ndw;
	for (; ndw > 0; ndw -= 2) {
		ib->ptr[ib->length_dw++] = lower_32_bits(value);
		ib->ptr[ib->length_dw++] = upper_32_bits(value);
		value += incr;
	}
}