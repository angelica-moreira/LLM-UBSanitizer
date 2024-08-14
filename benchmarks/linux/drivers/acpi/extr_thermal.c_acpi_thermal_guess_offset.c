#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ valid; } ;
struct TYPE_5__ {int temperature; TYPE_1__ flags; } ;
struct TYPE_6__ {TYPE_2__ critical; } ;
struct acpi_thermal {int kelvin_offset; TYPE_3__ trips; } ;

/* Variables and functions */

__attribute__((used)) static void acpi_thermal_guess_offset(struct acpi_thermal *tz)
{
	if (tz->trips.critical.flags.valid &&
	    (tz->trips.critical.temperature % 5) == 1)
		tz->kelvin_offset = 2731;
	else
		tz->kelvin_offset = 2732;
}