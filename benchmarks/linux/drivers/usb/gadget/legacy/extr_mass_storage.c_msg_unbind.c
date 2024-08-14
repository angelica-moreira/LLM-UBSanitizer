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
struct usb_composite_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  f_msg ; 
 int /*<<< orphan*/  fi_msg ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ ** otg_desc ; 
 int /*<<< orphan*/  usb_put_function (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_put_function_instance (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int msg_unbind(struct usb_composite_dev *cdev)
{
	if (!IS_ERR(f_msg))
		usb_put_function(f_msg);

	if (!IS_ERR(fi_msg))
		usb_put_function_instance(fi_msg);

	kfree(otg_desc[0]);
	otg_desc[0] = NULL;

	return 0;
}