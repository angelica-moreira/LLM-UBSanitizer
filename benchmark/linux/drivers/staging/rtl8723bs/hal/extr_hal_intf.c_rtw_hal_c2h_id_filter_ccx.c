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
struct TYPE_2__ {int /*<<< orphan*/  c2h_id_filter_ccx; } ;
struct adapter {TYPE_1__ HalFunc; } ;
typedef  int /*<<< orphan*/  c2h_id_filter ;

/* Variables and functions */

c2h_id_filter rtw_hal_c2h_id_filter_ccx(struct adapter *adapter)
{
	return adapter->HalFunc.c2h_id_filter_ccx;
}