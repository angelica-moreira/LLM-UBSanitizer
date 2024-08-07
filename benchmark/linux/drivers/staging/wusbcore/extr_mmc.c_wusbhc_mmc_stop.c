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
struct wusbhc {int /*<<< orphan*/  mutex; int /*<<< orphan*/  (* stop ) (struct wusbhc*,int /*<<< orphan*/ ) ;scalar_t__ active; } ;

/* Variables and functions */
 int /*<<< orphan*/  WUSB_CHANNEL_STOP_DELAY_MS ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct wusbhc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void wusbhc_mmc_stop(struct wusbhc *wusbhc)
{
	mutex_lock(&wusbhc->mutex);
	wusbhc->active = 0;
	wusbhc->stop(wusbhc, WUSB_CHANNEL_STOP_DELAY_MS);
	mutex_unlock(&wusbhc->mutex);
}