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
typedef  int /*<<< orphan*/  cpumask_t ;

/* Variables and functions */
 int __qcom_scm_set_cold_boot_addr (void*,int /*<<< orphan*/  const*) ; 

int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
	return __qcom_scm_set_cold_boot_addr(entry, cpus);
}