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
struct acpi_ec {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  EC_FLAGS_GPE_MASKED ; 
 int /*<<< orphan*/  acpi_ec_disable_gpe (struct acpi_ec*,int) ; 
 int /*<<< orphan*/  ec_dbg_drv (char*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void acpi_ec_mask_gpe(struct acpi_ec *ec)
{
	if (!test_bit(EC_FLAGS_GPE_MASKED, &ec->flags)) {
		acpi_ec_disable_gpe(ec, false);
		ec_dbg_drv("Polling enabled");
		set_bit(EC_FLAGS_GPE_MASKED, &ec->flags);
	}
}