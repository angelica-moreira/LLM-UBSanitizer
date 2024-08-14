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
struct uart_port {int dummy; } ;

/* Variables and functions */
 unsigned int TIOCSER_TEMT ; 
 unsigned int UART_GET_STATUS (struct uart_port*) ; 
 unsigned int UART_STATUS_THE ; 

__attribute__((used)) static unsigned int apbuart_tx_empty(struct uart_port *port)
{
	unsigned int status = UART_GET_STATUS(port);
	return status & UART_STATUS_THE ? TIOCSER_TEMT : 0;
}