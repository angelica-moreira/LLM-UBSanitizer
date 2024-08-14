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
typedef  int u32 ;
typedef  int dma_addr_t ;
struct TYPE_2__ {void* Address; void* FlagsLength; } ;
typedef  TYPE_1__ Mpi2SGESimple32_t ;

/* Variables and functions */
 int MPI2_SGE_FLAGS_32_BIT_ADDRESSING ; 
 int MPI2_SGE_FLAGS_SHIFT ; 
 int MPI2_SGE_FLAGS_SYSTEM_ADDRESS ; 
 void* cpu_to_le32 (int) ; 

__attribute__((used)) static void
_base_add_sg_single_32(void *paddr, u32 flags_length, dma_addr_t dma_addr)
{
	Mpi2SGESimple32_t *sgel = paddr;

	flags_length |= (MPI2_SGE_FLAGS_32_BIT_ADDRESSING |
	    MPI2_SGE_FLAGS_SYSTEM_ADDRESS) << MPI2_SGE_FLAGS_SHIFT;
	sgel->FlagsLength = cpu_to_le32(flags_length);
	sgel->Address = cpu_to_le32(dma_addr);
}