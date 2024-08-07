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
typedef  int /*<<< orphan*/  u32 ;
struct rt3883_pci_controller {unsigned int base; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void rt3883_pci_w32(struct rt3883_pci_controller *rpc,
				  u32 val, unsigned reg)
{
	iowrite32(val, rpc->base + reg);
}