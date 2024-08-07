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
 int /*<<< orphan*/  DPRINT (char*,char const*,char const*) ; 
 int command_status ; 
 int /*<<< orphan*/  delayed_work_pending (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fd_timeout ; 
 int /*<<< orphan*/  fdc_busy ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void is_alive(const char *func, const char *message)
{
	/* this routine checks whether the floppy driver is "alive" */
	if (test_bit(0, &fdc_busy) && command_status < 2 &&
	    !delayed_work_pending(&fd_timeout)) {
		DPRINT("%s: timeout handler died.  %s\n", func, message);
	}
}