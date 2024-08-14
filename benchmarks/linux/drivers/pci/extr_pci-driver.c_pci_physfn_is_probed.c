#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct pci_dev {TYPE_1__* physfn; scalar_t__ is_virtfn; } ;
struct TYPE_2__ {scalar_t__ is_probed; } ;

/* Variables and functions */

__attribute__((used)) static bool pci_physfn_is_probed(struct pci_dev *dev)
{
#ifdef CONFIG_PCI_IOV
	return dev->is_virtfn && dev->physfn->is_probed;
#else
	return false;
#endif
}