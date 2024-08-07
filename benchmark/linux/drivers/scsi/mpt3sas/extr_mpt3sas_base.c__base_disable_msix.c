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
struct MPT3SAS_ADAPTER {scalar_t__ msix_enable; int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_free_irq_vectors (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
_base_disable_msix(struct MPT3SAS_ADAPTER *ioc)
{
	if (!ioc->msix_enable)
		return;
	pci_free_irq_vectors(ioc->pdev);
	ioc->msix_enable = 0;
}