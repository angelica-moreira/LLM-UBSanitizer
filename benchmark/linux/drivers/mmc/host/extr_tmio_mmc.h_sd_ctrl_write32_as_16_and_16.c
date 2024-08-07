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
typedef  int u32 ;
struct tmio_mmc_host {int sdcard_irq_setbit_mask; int bus_shift; scalar_t__ ctl; } ;

/* Variables and functions */
 int CTL_IRQ_MASK ; 
 int CTL_STATUS ; 
 int /*<<< orphan*/  iowrite16 (int,scalar_t__) ; 

__attribute__((used)) static inline void sd_ctrl_write32_as_16_and_16(struct tmio_mmc_host *host,
						int addr, u32 val)
{
	if (addr == CTL_IRQ_MASK || addr == CTL_STATUS)
		val |= host->sdcard_irq_setbit_mask;

	iowrite16(val & 0xffff, host->ctl + (addr << host->bus_shift));
	iowrite16(val >> 16, host->ctl + ((addr + 2) << host->bus_shift));
}