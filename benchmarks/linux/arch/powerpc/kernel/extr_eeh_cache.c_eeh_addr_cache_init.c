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
struct TYPE_2__ {int /*<<< orphan*/  piar_lock; } ;

/* Variables and functions */
 TYPE_1__ pci_io_addr_cache_root ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

void eeh_addr_cache_init(void)
{
	spin_lock_init(&pci_io_addr_cache_root.piar_lock);
}