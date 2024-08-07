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
struct tty_port {TYPE_1__* client_ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* write_wakeup ) (struct tty_port*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct tty_port*) ; 

void tty_port_tty_wakeup(struct tty_port *port)
{
	port->client_ops->write_wakeup(port);
}