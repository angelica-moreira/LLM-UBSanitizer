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
struct a2091_hostdata {TYPE_1__* regs; } ;
struct Scsi_Host {int /*<<< orphan*/  host_lock; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {unsigned int ISTR; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int ISTR_INTS ; 
 unsigned int ISTR_INT_F ; 
 unsigned int ISTR_INT_P ; 
 struct a2091_hostdata* shost_priv (struct Scsi_Host*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  wd33c93_intr (struct Scsi_Host*) ; 

__attribute__((used)) static irqreturn_t a2091_intr(int irq, void *data)
{
	struct Scsi_Host *instance = data;
	struct a2091_hostdata *hdata = shost_priv(instance);
	unsigned int status = hdata->regs->ISTR;
	unsigned long flags;

	if (!(status & (ISTR_INT_F | ISTR_INT_P)) || !(status & ISTR_INTS))
		return IRQ_NONE;

	spin_lock_irqsave(instance->host_lock, flags);
	wd33c93_intr(instance);
	spin_unlock_irqrestore(instance->host_lock, flags);
	return IRQ_HANDLED;
}