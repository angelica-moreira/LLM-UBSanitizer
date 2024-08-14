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

/* Variables and functions */
 int CVMX_FPA_PACKET_POOL ; 
 int cvm_oct_fill_hw_memory (int,int,int) ; 
 int cvm_oct_fill_hw_skbuff (int,int,int) ; 

int cvm_oct_mem_fill_fpa(int pool, int size, int elements)
{
	int freed;

	if (pool == CVMX_FPA_PACKET_POOL)
		freed = cvm_oct_fill_hw_skbuff(pool, size, elements);
	else
		freed = cvm_oct_fill_hw_memory(pool, size, elements);
	return freed;
}