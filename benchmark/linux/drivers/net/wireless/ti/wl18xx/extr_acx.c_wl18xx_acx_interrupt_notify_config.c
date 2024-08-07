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
struct wl18xx_acx_interrupt_notify {int enable; } ;
struct wl1271 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACX_INTERRUPT_NOTIFY ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  kfree (struct wl18xx_acx_interrupt_notify*) ; 
 struct wl18xx_acx_interrupt_notify* kzalloc (int,int /*<<< orphan*/ ) ; 
 int wl1271_cmd_configure (struct wl1271*,int /*<<< orphan*/ ,struct wl18xx_acx_interrupt_notify*,int) ; 
 int /*<<< orphan*/  wl1271_warning (char*,int) ; 

int wl18xx_acx_interrupt_notify_config(struct wl1271 *wl,
				       bool action)
{
	struct wl18xx_acx_interrupt_notify *acx;
	int ret = 0;

	acx = kzalloc(sizeof(*acx), GFP_KERNEL);
	if (!acx) {
		ret = -ENOMEM;
		goto out;
	}

	acx->enable = action;
	ret = wl1271_cmd_configure(wl, ACX_INTERRUPT_NOTIFY, acx, sizeof(*acx));
	if (ret < 0) {
		wl1271_warning("acx interrupt notify setting failed: %d", ret);
		goto out;
	}

out:
	kfree(acx);
	return ret;
}