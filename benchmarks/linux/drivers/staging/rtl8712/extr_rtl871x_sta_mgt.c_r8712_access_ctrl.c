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
typedef  int u8 ;
struct wlan_acl_pool {int dummy; } ;

/* Variables and functions */

u8 r8712_access_ctrl(struct wlan_acl_pool *pacl_list, u8 *mac_addr)
{
	return true;
}