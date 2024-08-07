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
typedef  scalar_t__ u8 ;
struct ath_common {scalar_t__ priv; } ;
struct ath5k_hw {int /*<<< orphan*/  pdev; } ;

/* Variables and functions */
 int L1_CACHE_BYTES ; 
 int /*<<< orphan*/  PCI_CACHE_LINE_SIZE ; 
 int /*<<< orphan*/  pci_read_config_byte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*) ; 

__attribute__((used)) static void ath5k_pci_read_cachesize(struct ath_common *common, int *csz)
{
	struct ath5k_hw *ah = (struct ath5k_hw *) common->priv;
	u8 u8tmp;

	pci_read_config_byte(ah->pdev, PCI_CACHE_LINE_SIZE, &u8tmp);
	*csz = (int)u8tmp;

	/*
	 * This check was put in to avoid "unpleasant" consequences if
	 * the bootrom has not fully initialized all PCI devices.
	 * Sometimes the cache line size register is not set
	 */

	if (*csz == 0)
		*csz = L1_CACHE_BYTES >> 2;   /* Use the default size */
}