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
typedef  int u16 ;
struct wm8350 {int dummy; } ;
struct watchdog_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WM8350_SYSTEM_CONTROL_2 ; 
 int WM8350_WDOG_MODE_MASK ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct wm8350* watchdog_get_drvdata (struct watchdog_device*) ; 
 int /*<<< orphan*/  wdt_mutex ; 
 int /*<<< orphan*/  wm8350_reg_lock (struct wm8350*) ; 
 int wm8350_reg_read (struct wm8350*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wm8350_reg_unlock (struct wm8350*) ; 
 int wm8350_reg_write (struct wm8350*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int wm8350_wdt_start(struct watchdog_device *wdt_dev)
{
	struct wm8350 *wm8350 = watchdog_get_drvdata(wdt_dev);
	int ret;
	u16 reg;

	mutex_lock(&wdt_mutex);
	wm8350_reg_unlock(wm8350);

	reg = wm8350_reg_read(wm8350, WM8350_SYSTEM_CONTROL_2);
	reg &= ~WM8350_WDOG_MODE_MASK;
	reg |= 0x20;
	ret = wm8350_reg_write(wm8350, WM8350_SYSTEM_CONTROL_2, reg);

	wm8350_reg_lock(wm8350);
	mutex_unlock(&wdt_mutex);

	return ret;
}