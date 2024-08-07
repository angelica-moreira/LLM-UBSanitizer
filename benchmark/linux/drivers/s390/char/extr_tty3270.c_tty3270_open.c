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
struct tty_struct {struct tty3270* driver_data; } ;
struct tty_port {int /*<<< orphan*/  count; } ;
struct tty3270 {struct tty_port port; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  tty_port_tty_set (struct tty_port*,struct tty_struct*) ; 

__attribute__((used)) static int
tty3270_open(struct tty_struct *tty, struct file *filp)
{
	struct tty3270 *tp = tty->driver_data;
	struct tty_port *port = &tp->port;

	port->count++;
	tty_port_tty_set(port, tty);
	return 0;
}