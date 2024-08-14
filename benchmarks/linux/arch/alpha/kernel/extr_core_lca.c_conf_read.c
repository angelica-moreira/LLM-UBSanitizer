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
typedef  unsigned long* vulp ;
typedef  unsigned int* vuip ;

/* Variables and functions */
 scalar_t__ LCA_IOC_STAT0 ; 
 unsigned long LCA_IOC_STAT0_CODE_MASK ; 
 unsigned long LCA_IOC_STAT0_CODE_SHIFT ; 
 unsigned long LCA_IOC_STAT0_ERR ; 
 int /*<<< orphan*/  draina () ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  printk (char*,unsigned long) ; 
 int /*<<< orphan*/  wrmces (int) ; 

__attribute__((used)) static unsigned int
conf_read(unsigned long addr)
{
	unsigned long flags, code, stat0;
	unsigned int value;

	local_irq_save(flags);

	/* Reset status register to avoid losing errors.  */
	stat0 = *(vulp)LCA_IOC_STAT0;
	*(vulp)LCA_IOC_STAT0 = stat0;
	mb();

	/* Access configuration space.  */
	value = *(vuip)addr;
	draina();

	stat0 = *(vulp)LCA_IOC_STAT0;
	if (stat0 & LCA_IOC_STAT0_ERR) {
		code = ((stat0 >> LCA_IOC_STAT0_CODE_SHIFT)
			& LCA_IOC_STAT0_CODE_MASK);
		if (code != 1) {
			printk("lca.c:conf_read: got stat0=%lx\n", stat0);
		}

		/* Reset error status.  */
		*(vulp)LCA_IOC_STAT0 = stat0;
		mb();

		/* Reset machine check.  */
		wrmces(0x7);

		value = 0xffffffff;
	}
	local_irq_restore(flags);
	return value;
}