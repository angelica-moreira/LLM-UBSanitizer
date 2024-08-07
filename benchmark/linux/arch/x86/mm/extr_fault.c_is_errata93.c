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
typedef  unsigned long u64 ;
struct pt_regs {unsigned long ip; } ;
struct TYPE_2__ {scalar_t__ x86_vendor; int x86; } ;

/* Variables and functions */
 unsigned long MODULES_END ; 
 unsigned long MODULES_VADDR ; 
 scalar_t__ X86_VENDOR_AMD ; 
 scalar_t__ _etext ; 
 scalar_t__ _stext ; 
 TYPE_1__ boot_cpu_data ; 
 int /*<<< orphan*/  errata93_warning ; 
 int /*<<< orphan*/  printk_once (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int is_errata93(struct pt_regs *regs, unsigned long address)
{
#if defined(CONFIG_X86_64) && defined(CONFIG_CPU_SUP_AMD)
	if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD
	    || boot_cpu_data.x86 != 0xf)
		return 0;

	if (address != regs->ip)
		return 0;

	if ((address >> 32) != 0)
		return 0;

	address |= 0xffffffffUL << 32;
	if ((address >= (u64)_stext && address <= (u64)_etext) ||
	    (address >= MODULES_VADDR && address <= MODULES_END)) {
		printk_once(errata93_warning);
		regs->ip = address;
		return 1;
	}
#endif
	return 0;
}