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
struct RxDesc {int /*<<< orphan*/  addr; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sis190_give_to_asic (struct RxDesc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void sis190_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
				      u32 rx_buf_sz)
{
	desc->addr = cpu_to_le32(mapping);
	sis190_give_to_asic(desc, rx_buf_sz);
}