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
struct ti_emif_data {scalar_t__ ti_emif_sram_virt; } ;

/* Variables and functions */
 scalar_t__ TI_EMIF_SRAM_SYMBOL_OFFSET (unsigned long) ; 

__attribute__((used)) static u32 sram_suspend_address(struct ti_emif_data *emif_data,
				unsigned long addr)
{
	return (emif_data->ti_emif_sram_virt +
		TI_EMIF_SRAM_SYMBOL_OFFSET(addr));
}