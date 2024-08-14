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
struct btc_coexist {int /*<<< orphan*/ * adapter; int /*<<< orphan*/  binded; } ;

/* Variables and functions */

__attribute__((used)) static bool halbtc_is_bt_coexist_available(struct btc_coexist *btcoexist)
{
	if (!btcoexist->binded || NULL == btcoexist->adapter)
		return false;

	return true;
}