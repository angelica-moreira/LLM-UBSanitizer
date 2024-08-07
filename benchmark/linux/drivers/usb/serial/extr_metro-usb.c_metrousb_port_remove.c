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
struct usb_serial_port {int dummy; } ;
struct metrousb_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct metrousb_private*) ; 
 struct metrousb_private* usb_get_serial_port_data (struct usb_serial_port*) ; 

__attribute__((used)) static int metrousb_port_remove(struct usb_serial_port *port)
{
	struct metrousb_private *metro_priv;

	metro_priv = usb_get_serial_port_data(port);
	kfree(metro_priv);

	return 0;
}