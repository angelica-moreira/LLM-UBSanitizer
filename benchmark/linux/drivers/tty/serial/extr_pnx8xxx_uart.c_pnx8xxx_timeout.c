#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; scalar_t__ state; } ;
struct pnx8xxx_port {int /*<<< orphan*/  timer; TYPE_1__ port; } ;

/* Variables and functions */
 scalar_t__ MCTRL_TIMEOUT ; 
 struct pnx8xxx_port* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  pnx8xxx_mctrl_check (struct pnx8xxx_port*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct pnx8xxx_port* sport ; 
 int /*<<< orphan*/  timer ; 

__attribute__((used)) static void pnx8xxx_timeout(struct timer_list *t)
{
	struct pnx8xxx_port *sport = from_timer(sport, t, timer);
	unsigned long flags;

	if (sport->port.state) {
		spin_lock_irqsave(&sport->port.lock, flags);
		pnx8xxx_mctrl_check(sport);
		spin_unlock_irqrestore(&sport->port.lock, flags);

		mod_timer(&sport->timer, jiffies + MCTRL_TIMEOUT);
	}
}