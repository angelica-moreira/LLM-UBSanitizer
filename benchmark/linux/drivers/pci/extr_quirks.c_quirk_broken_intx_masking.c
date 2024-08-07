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
struct pci_dev {int broken_intx_masking; } ;

/* Variables and functions */

__attribute__((used)) static void quirk_broken_intx_masking(struct pci_dev *dev)
{
	dev->broken_intx_masking = 1;
}