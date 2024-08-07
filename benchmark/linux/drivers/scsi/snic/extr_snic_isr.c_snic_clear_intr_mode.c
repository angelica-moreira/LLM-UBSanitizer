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
struct snic {int /*<<< orphan*/  vdev; int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  VNIC_DEV_INTR_MODE_INTX ; 
 int /*<<< orphan*/  pci_free_irq_vectors (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svnic_dev_set_intr_mode (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
snic_clear_intr_mode(struct snic *snic)
{
	pci_free_irq_vectors(snic->pdev);
	svnic_dev_set_intr_mode(snic->vdev, VNIC_DEV_INTR_MODE_INTX);
}