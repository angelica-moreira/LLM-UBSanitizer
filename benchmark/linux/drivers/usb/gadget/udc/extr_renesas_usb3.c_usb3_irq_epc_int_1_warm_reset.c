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
 int /*<<< orphan*/  USB3_USB_COM_CON ; 
 int /*<<< orphan*/  USB_COM_CON_EP0_EN ; 
 int /*<<< orphan*/  USB_INT_1_SPEED ; 
 int /*<<< orphan*/  usb3_enable_irq_1 (struct renesas_usb3*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb3_reset_epc (struct renesas_usb3*) ; 
 int /*<<< orphan*/  usb3_set_bit (struct renesas_usb3*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb3_start_operation_for_usb3 (struct renesas_usb3*) ; 

__attribute__((used)) static void usb3_irq_epc_int_1_warm_reset(struct renesas_usb3 *usb3)
{
	usb3_reset_epc(usb3);
	usb3_set_bit(usb3, USB_COM_CON_EP0_EN, USB3_USB_COM_CON);

	usb3_start_operation_for_usb3(usb3);
	usb3_enable_irq_1(usb3, USB_INT_1_SPEED);
}