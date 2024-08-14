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
 int /*<<< orphan*/  VGA_PORT_HGSMI_HOST ; 
 int /*<<< orphan*/  outl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void vbox_clear_irq(void)
{
	outl((u32)~0, VGA_PORT_HGSMI_HOST);
}