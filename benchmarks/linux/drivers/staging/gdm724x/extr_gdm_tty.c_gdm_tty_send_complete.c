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
struct gdm {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int /*<<< orphan*/  GDM_TTY_READY (struct gdm*) ; 
 int /*<<< orphan*/  tty_port_tty_wakeup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gdm_tty_send_complete(void *arg)
{
	struct gdm *gdm = arg;

	if (!GDM_TTY_READY(gdm))
		return;

	tty_port_tty_wakeup(&gdm->port);
}