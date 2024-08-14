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
 char const* DRIVER_NAME ; 
 scalar_t__ PORT_MPS2UART ; 

__attribute__((used)) static const char *mps2_uart_type(struct uart_port *port)
{
	return (port->type == PORT_MPS2UART) ? DRIVER_NAME : NULL;
}