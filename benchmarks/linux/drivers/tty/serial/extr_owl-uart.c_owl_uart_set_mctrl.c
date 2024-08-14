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
typedef  int /*<<< orphan*/  u32 ;
struct uart_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OWL_UART_CTL ; 
 int /*<<< orphan*/  OWL_UART_CTL_LBEN ; 
 unsigned int TIOCM_LOOP ; 
 int /*<<< orphan*/  owl_uart_read (struct uart_port*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  owl_uart_write (struct uart_port*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void owl_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
	u32 ctl;

	ctl = owl_uart_read(port, OWL_UART_CTL);

	if (mctrl & TIOCM_LOOP)
		ctl |= OWL_UART_CTL_LBEN;
	else
		ctl &= ~OWL_UART_CTL_LBEN;

	owl_uart_write(port, ctl, OWL_UART_CTL);
}