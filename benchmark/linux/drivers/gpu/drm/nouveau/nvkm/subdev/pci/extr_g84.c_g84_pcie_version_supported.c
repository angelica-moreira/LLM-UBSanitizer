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
struct nvkm_pci {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int
g84_pcie_version_supported(struct nvkm_pci *pci)
{
	/* g84 and g86 report wrong information about what they support */
	return 1;
}