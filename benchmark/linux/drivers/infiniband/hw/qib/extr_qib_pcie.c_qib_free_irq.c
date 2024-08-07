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
struct qib_devdata {int /*<<< orphan*/  pcidev; } ;

/* Variables and functions */
 int /*<<< orphan*/  pci_free_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct qib_devdata*) ; 
 int /*<<< orphan*/  pci_free_irq_vectors (int /*<<< orphan*/ ) ; 

void qib_free_irq(struct qib_devdata *dd)
{
	pci_free_irq(dd->pcidev, 0, dd);
	pci_free_irq_vectors(dd->pcidev);
}