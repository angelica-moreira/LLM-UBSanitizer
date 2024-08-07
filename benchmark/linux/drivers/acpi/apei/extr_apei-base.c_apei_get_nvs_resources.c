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
struct apei_resources {int dummy; } ;

/* Variables and functions */
 int acpi_nvs_for_each_region (int /*<<< orphan*/ ,struct apei_resources*) ; 
 int /*<<< orphan*/  apei_get_res_callback ; 

__attribute__((used)) static int apei_get_nvs_resources(struct apei_resources *resources)
{
	return acpi_nvs_for_each_region(apei_get_res_callback, resources);
}