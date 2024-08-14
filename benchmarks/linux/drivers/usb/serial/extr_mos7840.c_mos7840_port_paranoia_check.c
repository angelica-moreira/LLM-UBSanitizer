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
struct usb_serial_port {int /*<<< orphan*/  serial; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*,char const*) ; 

__attribute__((used)) static int mos7840_port_paranoia_check(struct usb_serial_port *port,
				       const char *function)
{
	if (!port) {
		pr_debug("%s - port == NULL\n", function);
		return -1;
	}
	if (!port->serial) {
		pr_debug("%s - port->serial == NULL\n", function);
		return -1;
	}

	return 0;
}