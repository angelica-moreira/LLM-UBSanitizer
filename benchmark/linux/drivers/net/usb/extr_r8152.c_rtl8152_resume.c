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
struct usb_interface {int dummy; } ;
struct r8152 {int /*<<< orphan*/  control; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  SELECTIVE_SUSPEND ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int rtl8152_runtime_resume (struct r8152*) ; 
 int rtl8152_system_resume (struct r8152*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct r8152* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static int rtl8152_resume(struct usb_interface *intf)
{
	struct r8152 *tp = usb_get_intfdata(intf);
	int ret;

	mutex_lock(&tp->control);

	if (test_bit(SELECTIVE_SUSPEND, &tp->flags))
		ret = rtl8152_runtime_resume(tp);
	else
		ret = rtl8152_system_resume(tp);

	mutex_unlock(&tp->control);

	return ret;
}