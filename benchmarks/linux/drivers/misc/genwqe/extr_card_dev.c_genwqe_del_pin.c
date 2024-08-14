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
struct genwqe_file {int /*<<< orphan*/  pin_lock; } ;
struct dma_mapping {int /*<<< orphan*/  pin_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int genwqe_del_pin(struct genwqe_file *cfile, struct dma_mapping *m)
{
	unsigned long flags;

	spin_lock_irqsave(&cfile->pin_lock, flags);
	list_del(&m->pin_list);
	spin_unlock_irqrestore(&cfile->pin_lock, flags);

	return 0;
}