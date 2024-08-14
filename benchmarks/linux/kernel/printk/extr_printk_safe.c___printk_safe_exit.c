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

/* Variables and functions */
 int /*<<< orphan*/  printk_context ; 
 int /*<<< orphan*/  this_cpu_dec (int /*<<< orphan*/ ) ; 

void __printk_safe_exit(void)
{
	this_cpu_dec(printk_context);
}