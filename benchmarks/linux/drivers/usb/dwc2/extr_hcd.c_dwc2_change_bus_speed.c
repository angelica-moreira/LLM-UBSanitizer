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
struct usb_hcd {int dummy; } ;
struct TYPE_2__ {int speed; } ;
struct dwc2_hsotg {int /*<<< orphan*/  wf_otg; int /*<<< orphan*/  wq_otg; TYPE_1__ params; } ;

/* Variables and functions */
 struct dwc2_hsotg* dwc2_hcd_to_hsotg (struct usb_hcd*) ; 
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void dwc2_change_bus_speed(struct usb_hcd *hcd, int speed)
{
	struct dwc2_hsotg *hsotg = dwc2_hcd_to_hsotg(hcd);

	if (hsotg->params.speed == speed)
		return;

	hsotg->params.speed = speed;
	queue_work(hsotg->wq_otg, &hsotg->wf_otg);
}