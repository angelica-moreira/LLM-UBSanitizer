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
 int /*<<< orphan*/  rtl_csi_access_enable (struct rtl8169_private*,int) ; 

__attribute__((used)) static void rtl_set_def_aspm_entry_latency(struct rtl8169_private *tp)
{
	rtl_csi_access_enable(tp, 0x27);
}