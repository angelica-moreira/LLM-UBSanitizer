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
struct qlcnic_adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  qlcnic_remove_diag_entries (struct qlcnic_adapter*) ; 

void qlcnic_82xx_remove_sysfs(struct qlcnic_adapter *adapter)
{
	qlcnic_remove_diag_entries(adapter);
}