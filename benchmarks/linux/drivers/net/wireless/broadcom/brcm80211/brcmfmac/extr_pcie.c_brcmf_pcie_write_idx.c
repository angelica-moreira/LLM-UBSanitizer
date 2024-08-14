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
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct brcmf_pciedev_info {int /*<<< orphan*/ * idxbuf; } ;

/* Variables and functions */

__attribute__((used)) static void
brcmf_pcie_write_idx(struct brcmf_pciedev_info *devinfo, u32 mem_offset,
		     u16 value)
{
	u16 *address = devinfo->idxbuf + mem_offset;

	*(address) = value;
}