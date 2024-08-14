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
struct ath10k {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath10k_ce_disable_interrupts (struct ath10k*) ; 
 int /*<<< orphan*/  ath10k_pci_disable_and_clear_legacy_irq (struct ath10k*) ; 
 int /*<<< orphan*/  ath10k_pci_irq_msi_fw_mask (struct ath10k*) ; 

__attribute__((used)) static void ath10k_pci_irq_disable(struct ath10k *ar)
{
	ath10k_ce_disable_interrupts(ar);
	ath10k_pci_disable_and_clear_legacy_irq(ar);
	ath10k_pci_irq_msi_fw_mask(ar);
}