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
struct usb_gadget {int dummy; } ;
struct pxa_udc {int /*<<< orphan*/  udc_command; int /*<<< orphan*/  gpiod; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  dplus_pullup (struct pxa_udc*,int) ; 
 scalar_t__ should_disable_udc (struct pxa_udc*) ; 
 scalar_t__ should_enable_udc (struct pxa_udc*) ; 
 struct pxa_udc* to_gadget_udc (struct usb_gadget*) ; 
 int /*<<< orphan*/  udc_disable (struct pxa_udc*) ; 
 int /*<<< orphan*/  udc_enable (struct pxa_udc*) ; 

__attribute__((used)) static int pxa_udc_pullup(struct usb_gadget *_gadget, int is_active)
{
	struct pxa_udc *udc = to_gadget_udc(_gadget);

	if (!udc->gpiod && !udc->udc_command)
		return -EOPNOTSUPP;

	dplus_pullup(udc, is_active);

	if (should_enable_udc(udc))
		udc_enable(udc);
	if (should_disable_udc(udc))
		udc_disable(udc);
	return 0;
}