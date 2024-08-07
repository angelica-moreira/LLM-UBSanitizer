#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct rtl_priv {int dummy; } ;
struct TYPE_2__ {int bt_lps_on; } ;
struct btc_coexist {TYPE_1__ bt_info; } ;

/* Variables and functions */
 struct btc_coexist* rtl_btc_coexist (struct rtl_priv*) ; 

bool rtl_btc_is_bt_lps_on(struct rtl_priv *rtlpriv)
{
	struct btc_coexist *btcoexist = rtl_btc_coexist(rtlpriv);

	if (!btcoexist)
		return false;

	return btcoexist->bt_info.bt_lps_on;
}