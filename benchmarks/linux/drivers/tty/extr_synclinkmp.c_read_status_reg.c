#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ statctrl_base; } ;
typedef  TYPE_1__ SLMP_INFO ;

/* Variables and functions */

__attribute__((used)) static unsigned char read_status_reg(SLMP_INFO * info)
{
	unsigned char *RegAddr = (unsigned char *)info->statctrl_base;
	return *RegAddr;
}