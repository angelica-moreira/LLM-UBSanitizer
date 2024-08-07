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
typedef  int /*<<< orphan*/  u16 ;
struct wil_ring_dma_addr {int /*<<< orphan*/  addr_high; int /*<<< orphan*/  addr_low; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lower_32_bits (int /*<<< orphan*/ ) ; 
 scalar_t__ upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void wil_desc_addr_set(struct wil_ring_dma_addr *addr,
				     dma_addr_t pa)
{
	addr->addr_low = cpu_to_le32(lower_32_bits(pa));
	addr->addr_high = cpu_to_le16((u16)upper_32_bits(pa));
}