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
struct pci_bus {int dummy; } ;
typedef  int resource_size_t ;

/* Variables and functions */

__attribute__((used)) static resource_size_t cxl_pci_window_alignment(struct pci_bus *bus,
						unsigned long type)
{
	return 1;
}