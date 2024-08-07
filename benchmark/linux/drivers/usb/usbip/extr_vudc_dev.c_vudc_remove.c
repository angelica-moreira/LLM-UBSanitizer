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
struct vudc {int /*<<< orphan*/  gadget; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cleanup_vudc_hw (struct vudc*) ; 
 int /*<<< orphan*/  kfree (struct vudc*) ; 
 struct vudc* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  usb_del_gadget_udc (int /*<<< orphan*/ *) ; 

int vudc_remove(struct platform_device *pdev)
{
	struct vudc *udc = platform_get_drvdata(pdev);

	usb_del_gadget_udc(&udc->gadget);
	cleanup_vudc_hw(udc);
	kfree(udc);
	return 0;
}