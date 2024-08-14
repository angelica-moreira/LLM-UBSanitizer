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
struct uart_port {int dummy; } ;
struct TYPE_2__ {scalar_t__ (* tx_empty ) (struct uart_port*) ;} ;

/* Variables and functions */
 unsigned int TIOCSER_TEMT ; 
 TYPE_1__* psc_ops ; 
 scalar_t__ stub1 (struct uart_port*) ; 

__attribute__((used)) static unsigned int
mpc52xx_uart_tx_empty(struct uart_port *port)
{
	return psc_ops->tx_empty(port) ? TIOCSER_TEMT : 0;
}