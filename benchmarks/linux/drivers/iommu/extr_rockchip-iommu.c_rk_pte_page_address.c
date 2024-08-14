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
typedef  scalar_t__ u32 ;
typedef  int phys_addr_t ;

/* Variables and functions */
 int RK_PTE_PAGE_ADDRESS_MASK ; 

__attribute__((used)) static inline phys_addr_t rk_pte_page_address(u32 pte)
{
	return (phys_addr_t)pte & RK_PTE_PAGE_ADDRESS_MASK;
}