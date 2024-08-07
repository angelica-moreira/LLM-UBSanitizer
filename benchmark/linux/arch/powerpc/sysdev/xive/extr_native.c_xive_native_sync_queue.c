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

/* Variables and functions */
 int /*<<< orphan*/  XIVE_SYNC_QUEUE ; 
 int /*<<< orphan*/  opal_xive_sync (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void xive_native_sync_queue(u32 hw_irq)
{
	opal_xive_sync(XIVE_SYNC_QUEUE, hw_irq);
}