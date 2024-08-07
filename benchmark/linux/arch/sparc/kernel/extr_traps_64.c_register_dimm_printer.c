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
typedef  scalar_t__ dimm_printer_t ;

/* Variables and functions */
 int EEXIST ; 
 scalar_t__ dimm_handler ; 
 int /*<<< orphan*/  dimm_handler_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int register_dimm_printer(dimm_printer_t func)
{
	unsigned long flags;
	int ret = 0;

	spin_lock_irqsave(&dimm_handler_lock, flags);
	if (!dimm_handler)
		dimm_handler = func;
	else
		ret = -EEXIST;
	spin_unlock_irqrestore(&dimm_handler_lock, flags);

	return ret;
}