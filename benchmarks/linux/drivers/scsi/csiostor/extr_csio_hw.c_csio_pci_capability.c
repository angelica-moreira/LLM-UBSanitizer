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
struct pci_dev {int dummy; } ;

/* Variables and functions */
 int pci_find_capability (struct pci_dev*,int) ; 

__attribute__((used)) static int
csio_pci_capability(struct pci_dev *pdev, int cap, int *pos)
{
	*pos = pci_find_capability(pdev, cap);
	if (*pos)
		return 0;

	return -1;
}