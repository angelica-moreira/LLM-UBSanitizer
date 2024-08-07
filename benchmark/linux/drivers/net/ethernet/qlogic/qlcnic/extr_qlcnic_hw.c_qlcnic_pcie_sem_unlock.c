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
 int /*<<< orphan*/  PCIE_SEM_UNLOCK (int) ; 
 int /*<<< orphan*/  QLCNIC_PCIE_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QLCRD32 (struct qlcnic_adapter*,int /*<<< orphan*/ ,int*) ; 

void
qlcnic_pcie_sem_unlock(struct qlcnic_adapter *adapter, int sem)
{
	int err = 0;

	QLCRD32(adapter, QLCNIC_PCIE_REG(PCIE_SEM_UNLOCK(sem)), &err);
}