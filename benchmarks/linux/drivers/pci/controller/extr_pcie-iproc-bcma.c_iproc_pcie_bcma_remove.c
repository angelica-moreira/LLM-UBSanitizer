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
struct iproc_pcie {int dummy; } ;
struct bcma_device {int dummy; } ;

/* Variables and functions */
 struct iproc_pcie* bcma_get_drvdata (struct bcma_device*) ; 
 int /*<<< orphan*/  iproc_pcie_remove (struct iproc_pcie*) ; 

__attribute__((used)) static void iproc_pcie_bcma_remove(struct bcma_device *bdev)
{
	struct iproc_pcie *pcie = bcma_get_drvdata(bdev);

	iproc_pcie_remove(pcie);
}