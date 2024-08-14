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
struct whiteheat_private {int mcr; } ;
struct usb_serial_port {int dummy; } ;
struct tty_struct {struct usb_serial_port* driver_data; } ;

/* Variables and functions */
 unsigned int TIOCM_DTR ; 
 unsigned int TIOCM_RTS ; 
 int UART_MCR_DTR ; 
 int UART_MCR_RTS ; 
 int /*<<< orphan*/  firm_get_dtr_rts (struct usb_serial_port*) ; 
 struct whiteheat_private* usb_get_serial_port_data (struct usb_serial_port*) ; 

__attribute__((used)) static int whiteheat_tiocmget(struct tty_struct *tty)
{
	struct usb_serial_port *port = tty->driver_data;
	struct whiteheat_private *info = usb_get_serial_port_data(port);
	unsigned int modem_signals = 0;

	firm_get_dtr_rts(port);
	if (info->mcr & UART_MCR_DTR)
		modem_signals |= TIOCM_DTR;
	if (info->mcr & UART_MCR_RTS)
		modem_signals |= TIOCM_RTS;

	return modem_signals;
}