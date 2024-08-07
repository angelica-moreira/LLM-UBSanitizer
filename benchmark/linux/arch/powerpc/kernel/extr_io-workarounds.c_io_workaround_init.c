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

/* Variables and functions */
 int io_workaround_inited ; 
 int /*<<< orphan*/  iowa_pci_io ; 
 int /*<<< orphan*/  ppc_pci_io ; 

__attribute__((used)) static void io_workaround_init(void)
{
	if (io_workaround_inited)
		return;
	ppc_pci_io = iowa_pci_io;
	io_workaround_inited = true;
}