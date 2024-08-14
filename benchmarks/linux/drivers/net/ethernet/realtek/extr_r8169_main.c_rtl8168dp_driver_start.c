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
struct rtl8169_private {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OOB_CMD_DRIVER_START ; 
 int /*<<< orphan*/  r8168dp_oob_notify (struct rtl8169_private*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtl_dp_ocp_read_cond ; 
 int /*<<< orphan*/  rtl_msleep_loop_wait_high (struct rtl8169_private*,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static void rtl8168dp_driver_start(struct rtl8169_private *tp)
{
	r8168dp_oob_notify(tp, OOB_CMD_DRIVER_START);
	rtl_msleep_loop_wait_high(tp, &rtl_dp_ocp_read_cond, 10, 10);
}