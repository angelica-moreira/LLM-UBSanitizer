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
struct tty_struct {struct fwtty_port* driver_data; } ;
struct fwtty_port {int /*<<< orphan*/  port; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int tty_port_open (int /*<<< orphan*/ *,struct tty_struct*,struct file*) ; 

__attribute__((used)) static int fwtty_open(struct tty_struct *tty, struct file *fp)
{
	struct fwtty_port *port = tty->driver_data;

	return tty_port_open(&port->port, tty, fp);
}