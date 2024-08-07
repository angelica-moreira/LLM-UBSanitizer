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
struct uart_port {unsigned int (* get_divisor ) (struct uart_port*,unsigned int,unsigned int*) ;} ;

/* Variables and functions */
 unsigned int serial8250_do_get_divisor (struct uart_port*,unsigned int,unsigned int*) ; 
 unsigned int stub1 (struct uart_port*,unsigned int,unsigned int*) ; 

__attribute__((used)) static unsigned int serial8250_get_divisor(struct uart_port *port,
					   unsigned int baud,
					   unsigned int *frac)
{
	if (port->get_divisor)
		return port->get_divisor(port, baud, frac);

	return serial8250_do_get_divisor(port, baud, frac);
}