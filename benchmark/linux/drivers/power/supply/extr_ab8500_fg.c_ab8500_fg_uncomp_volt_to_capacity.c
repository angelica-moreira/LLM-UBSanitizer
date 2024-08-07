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
struct ab8500_fg {int /*<<< orphan*/  vbat; } ;

/* Variables and functions */
 int /*<<< orphan*/  ab8500_fg_bat_voltage (struct ab8500_fg*) ; 
 int ab8500_fg_volt_to_capacity (struct ab8500_fg*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ab8500_fg_uncomp_volt_to_capacity(struct ab8500_fg *di)
{
	di->vbat = ab8500_fg_bat_voltage(di);
	return ab8500_fg_volt_to_capacity(di, di->vbat);
}