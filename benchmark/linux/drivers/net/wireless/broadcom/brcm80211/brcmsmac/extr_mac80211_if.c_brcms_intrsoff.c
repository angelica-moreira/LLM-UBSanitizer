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
struct brcms_info {int /*<<< orphan*/  isr_lock; int /*<<< orphan*/  wlc; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcms_c_intrsoff (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

u32 brcms_intrsoff(struct brcms_info *wl)
{
	unsigned long flags;
	u32 status;

	spin_lock_irqsave(&wl->isr_lock, flags);
	status = brcms_c_intrsoff(wl->wlc);
	spin_unlock_irqrestore(&wl->isr_lock, flags);
	return status;
}