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
struct TYPE_2__ {int /*<<< orphan*/  (* init_default_value ) (struct adapter*) ;} ;
struct adapter {TYPE_1__ HalFunc; } ;

/* Variables and functions */
 scalar_t__ is_primary_adapter (struct adapter*) ; 
 int /*<<< orphan*/  stub1 (struct adapter*) ; 

void rtw_hal_def_value_init(struct adapter *padapter)
{
	if (is_primary_adapter(padapter))
		if (padapter->HalFunc.init_default_value)
			padapter->HalFunc.init_default_value(padapter);
}