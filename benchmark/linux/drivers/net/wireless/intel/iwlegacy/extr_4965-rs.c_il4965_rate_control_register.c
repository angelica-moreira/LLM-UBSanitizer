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

/* Variables and functions */
 int ieee80211_rate_control_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rs_4965_ops ; 

int
il4965_rate_control_register(void)
{
	return ieee80211_rate_control_register(&rs_4965_ops);
}