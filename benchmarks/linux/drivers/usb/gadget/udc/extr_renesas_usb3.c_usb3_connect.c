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
struct renesas_usb3 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  usb3_start_usb3_connection (struct renesas_usb3*) ; 
 scalar_t__ usb3_wakeup_usb3_phy (struct renesas_usb3*) ; 

__attribute__((used)) static void usb3_connect(struct renesas_usb3 *usb3)
{
	if (usb3_wakeup_usb3_phy(usb3))
		usb3_start_usb3_connection(usb3);
}