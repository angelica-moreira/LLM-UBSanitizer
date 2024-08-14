#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* otg; } ;
struct tahvo_usb {TYPE_2__ phy; } ;
struct TYPE_3__ {int /*<<< orphan*/  state; scalar_t__ gadget; } ;

/* Variables and functions */
 int /*<<< orphan*/  OTG_STATE_B_IDLE ; 
 int /*<<< orphan*/  usb_gadget_vbus_disconnect (scalar_t__) ; 

__attribute__((used)) static void tahvo_usb_stop_peripheral(struct tahvo_usb *tu)
{
	if (tu->phy.otg->gadget)
		usb_gadget_vbus_disconnect(tu->phy.otg->gadget);
	tu->phy.otg->state = OTG_STATE_B_IDLE;
}