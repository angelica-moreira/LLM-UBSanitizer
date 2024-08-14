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
typedef  int u8 ;
struct usb_serial_port {int dummy; } ;
struct f81232_private {int modem_status; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int UART_MSR_DCD ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct f81232_private* usb_get_serial_port_data (struct usb_serial_port*) ; 

__attribute__((used)) static int f81232_carrier_raised(struct usb_serial_port *port)
{
	u8 msr;
	struct f81232_private *priv = usb_get_serial_port_data(port);

	mutex_lock(&priv->lock);
	msr = priv->modem_status;
	mutex_unlock(&priv->lock);

	if (msr & UART_MSR_DCD)
		return 1;
	return 0;
}