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
typedef  scalar_t__ u32 ;

/* Variables and functions */
 scalar_t__ CLKCTRL_IDLEST_DISABLED ; 
 scalar_t__ _omap4_idlest (scalar_t__) ; 

__attribute__((used)) static bool _omap4_is_idle(u32 val)
{
	val = _omap4_idlest(val);

	return val == CLKCTRL_IDLEST_DISABLED;
}