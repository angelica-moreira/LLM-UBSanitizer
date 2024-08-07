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
struct device {int dummy; } ;
struct cb710_slot {int dummy; } ;
struct cb710_chip {int /*<<< orphan*/  slot_refs_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 struct cb710_slot* cb710_pdev_to_slot (int /*<<< orphan*/ ) ; 
 struct cb710_chip* cb710_slot_to_chip (struct cb710_slot*) ; 
 int /*<<< orphan*/  to_platform_device (struct device*) ; 

__attribute__((used)) static void cb710_release_slot(struct device *dev)
{
#ifdef CONFIG_CB710_DEBUG_ASSUMPTIONS
	struct cb710_slot *slot = cb710_pdev_to_slot(to_platform_device(dev));
	struct cb710_chip *chip = cb710_slot_to_chip(slot);

	/* slot struct can be freed now */
	atomic_dec(&chip->slot_refs_count);
#endif
}