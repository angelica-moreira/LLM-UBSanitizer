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
struct topstar_laptop {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int topstar_acpi_fncx_switch (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int topstar_acpi_init(struct topstar_laptop *topstar)
{
	return topstar_acpi_fncx_switch(topstar->device, true);
}