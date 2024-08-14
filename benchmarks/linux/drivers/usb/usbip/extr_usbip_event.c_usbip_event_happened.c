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
struct usbip_device {scalar_t__ event; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int usbip_event_happened(struct usbip_device *ud)
{
	int happened = 0;
	unsigned long flags;

	spin_lock_irqsave(&ud->lock, flags);
	if (ud->event != 0)
		happened = 1;
	spin_unlock_irqrestore(&ud->lock, flags);

	return happened;
}