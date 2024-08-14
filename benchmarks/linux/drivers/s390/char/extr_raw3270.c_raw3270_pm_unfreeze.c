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
struct raw3270_view {struct raw3270* dev; } ;
struct raw3270 {int /*<<< orphan*/  cdev; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  RAW3270_FLAGS_FROZEN ; 
 int /*<<< orphan*/  ccw_device_force_console (int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void raw3270_pm_unfreeze(struct raw3270_view *view)
{
#ifdef CONFIG_TN3270_CONSOLE
	struct raw3270 *rp;

	rp = view->dev;
	if (rp && test_bit(RAW3270_FLAGS_FROZEN, &rp->flags))
		ccw_device_force_console(rp->cdev);
#endif
}