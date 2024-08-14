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
struct wm97xx {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct wm97xx* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  wm97xx_remove_battery (struct wm97xx*) ; 
 int /*<<< orphan*/  wm97xx_unregister_touch (struct wm97xx*) ; 

__attribute__((used)) static int wm97xx_remove(struct device *dev)
{
	struct wm97xx *wm = dev_get_drvdata(dev);

	wm97xx_remove_battery(wm);
	wm97xx_unregister_touch(wm);

	return 0;
}