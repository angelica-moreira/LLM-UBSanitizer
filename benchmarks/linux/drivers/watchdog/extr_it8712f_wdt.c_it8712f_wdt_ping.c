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
 int WDT_RESET_GAME ; 
 int /*<<< orphan*/  address ; 
 int /*<<< orphan*/  inb (int /*<<< orphan*/ ) ; 
 int wdt_control_reg ; 

__attribute__((used)) static inline void it8712f_wdt_ping(void)
{
	if (wdt_control_reg & WDT_RESET_GAME)
		inb(address);
}