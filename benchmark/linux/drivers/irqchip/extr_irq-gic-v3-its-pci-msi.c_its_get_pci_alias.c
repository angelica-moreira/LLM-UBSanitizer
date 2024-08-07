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
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int its_get_pci_alias(struct pci_dev *pdev, u16 alias, void *data)
{
	struct pci_dev **alias_dev = data;

	*alias_dev = pdev;

	return 0;
}