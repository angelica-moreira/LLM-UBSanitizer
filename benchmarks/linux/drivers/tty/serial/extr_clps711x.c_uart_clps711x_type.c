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
struct uart_port {scalar_t__ type; } ;

/* Variables and functions */
 scalar_t__ PORT_CLPS711X ; 

__attribute__((used)) static const char *uart_clps711x_type(struct uart_port *port)
{
	return (port->type == PORT_CLPS711X) ? "CLPS711X" : NULL;
}