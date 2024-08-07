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
struct wifi_only_cfg {int dummy; } ;
struct rtl_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  exhalbtc_init_hw_config_wifi_only (struct wifi_only_cfg*) ; 
 struct wifi_only_cfg* rtl_btc_wifi_only (struct rtl_priv*) ; 

void rtl_btc_init_hw_config_wifi_only(struct rtl_priv *rtlpriv)
{
	struct wifi_only_cfg *wifionly_cfg = rtl_btc_wifi_only(rtlpriv);

	if (!wifionly_cfg)
		return;

	exhalbtc_init_hw_config_wifi_only(wifionly_cfg);
}