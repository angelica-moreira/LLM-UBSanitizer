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
struct wl1251 {int dummy; } ;
struct acx_bt_wlan_coex {int /*<<< orphan*/  enable; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACX_SG_ENABLE ; 
 int /*<<< orphan*/  DEBUG_ACX ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  SG_ENABLE ; 
 int /*<<< orphan*/  kfree (struct acx_bt_wlan_coex*) ; 
 struct acx_bt_wlan_coex* kzalloc (int,int /*<<< orphan*/ ) ; 
 int wl1251_cmd_configure (struct wl1251*,int /*<<< orphan*/ ,struct acx_bt_wlan_coex*,int) ; 
 int /*<<< orphan*/  wl1251_debug (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wl1251_warning (char*,int) ; 

int wl1251_acx_sg_enable(struct wl1251 *wl)
{
	struct acx_bt_wlan_coex *pta;
	int ret;

	wl1251_debug(DEBUG_ACX, "acx sg enable");

	pta = kzalloc(sizeof(*pta), GFP_KERNEL);
	if (!pta)
		return -ENOMEM;

	pta->enable = SG_ENABLE;

	ret = wl1251_cmd_configure(wl, ACX_SG_ENABLE, pta, sizeof(*pta));
	if (ret < 0) {
		wl1251_warning("failed to set softgemini enable: %d", ret);
		goto out;
	}

out:
	kfree(pta);
	return ret;
}