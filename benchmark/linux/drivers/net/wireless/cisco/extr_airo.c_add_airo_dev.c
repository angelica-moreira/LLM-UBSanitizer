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
struct airo_info {int /*<<< orphan*/  dev_list; int /*<<< orphan*/  pci; } ;

/* Variables and functions */
 int /*<<< orphan*/  airo_devices ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void add_airo_dev(struct airo_info *ai)
{
	/* Upper layers already keep track of PCI devices,
	 * so we only need to remember our non-PCI cards. */
	if (!ai->pci)
		list_add_tail(&ai->dev_list, &airo_devices);
}