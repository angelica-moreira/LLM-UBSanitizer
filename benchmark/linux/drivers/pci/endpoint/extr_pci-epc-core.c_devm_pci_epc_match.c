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
typedef  void pci_epc ;
struct device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int devm_pci_epc_match(struct device *dev, void *res, void *match_data)
{
	struct pci_epc **epc = res;

	return *epc == match_data;
}