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
struct usb_otg_caps {scalar_t__ adp_support; scalar_t__ hnp_support; scalar_t__ srp_support; } ;
struct ci_hdrc {scalar_t__* roles; scalar_t__ is_otg; TYPE_1__* platdata; } ;
struct TYPE_2__ {struct usb_otg_caps ci_otg_caps; } ;

/* Variables and functions */
 size_t CI_ROLE_GADGET ; 
 size_t CI_ROLE_HOST ; 

__attribute__((used)) static inline bool ci_otg_is_fsm_mode(struct ci_hdrc *ci)
{
#ifdef CONFIG_USB_OTG_FSM
	struct usb_otg_caps *otg_caps = &ci->platdata->ci_otg_caps;

	return ci->is_otg && ci->roles[CI_ROLE_HOST] &&
		ci->roles[CI_ROLE_GADGET] && (otg_caps->srp_support ||
		otg_caps->hnp_support || otg_caps->adp_support);
#else
	return false;
#endif
}