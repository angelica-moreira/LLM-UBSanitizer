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
struct dpu_hw_intr {struct dpu_hw_intr* save_irq_status; struct dpu_hw_intr* cache_irq_mask; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct dpu_hw_intr*) ; 

void dpu_hw_intr_destroy(struct dpu_hw_intr *intr)
{
	if (intr) {
		kfree(intr->cache_irq_mask);
		kfree(intr->save_irq_status);
		kfree(intr);
	}
}