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
struct acpi_processor {int dummy; } ;
struct acpi_device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void acpi_pss_perf_exit(struct acpi_processor *pr,
		struct acpi_device *device) {}