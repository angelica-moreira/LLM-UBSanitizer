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
 int /*<<< orphan*/  RESET ; 
 int /*<<< orphan*/  RESET_PORT ; 
 int /*<<< orphan*/  cobalt_machine_halt () ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void cobalt_machine_restart(char *command)
{
	writeb(RESET, RESET_PORT);

	/* we should never get here */
	cobalt_machine_halt();
}