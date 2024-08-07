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
struct tty_struct {int dummy; } ;
struct tty_port {int /*<<< orphan*/  lock; int /*<<< orphan*/  tty; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct tty_struct* tty_kref_get (int /*<<< orphan*/ ) ; 

struct tty_struct *tty_port_tty_get(struct tty_port *port)
{
	unsigned long flags;
	struct tty_struct *tty;

	spin_lock_irqsave(&port->lock, flags);
	tty = tty_kref_get(port->tty);
	spin_unlock_irqrestore(&port->lock, flags);
	return tty;
}