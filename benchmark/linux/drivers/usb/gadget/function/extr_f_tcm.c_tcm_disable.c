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
struct usb_function {int dummy; } ;
struct f_uas {int flags; } ;

/* Variables and functions */
 int USBG_IS_BOT ; 
 int USBG_IS_UAS ; 
 int /*<<< orphan*/  bot_cleanup_old_alt (struct f_uas*) ; 
 struct f_uas* to_f_uas (struct usb_function*) ; 
 int /*<<< orphan*/  uasp_cleanup_old_alt (struct f_uas*) ; 

__attribute__((used)) static void tcm_disable(struct usb_function *f)
{
	struct f_uas *fu = to_f_uas(f);

	if (fu->flags & USBG_IS_UAS)
		uasp_cleanup_old_alt(fu);
	else if (fu->flags & USBG_IS_BOT)
		bot_cleanup_old_alt(fu);
	fu->flags = 0;
}