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
struct intel_uncore_mmio_debug {scalar_t__ unclaimed_mmio_check; scalar_t__ saved_mmio_check; int /*<<< orphan*/  suspend_count; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mmio_debug_suspend(struct intel_uncore_mmio_debug *mmio_debug)
{
	lockdep_assert_held(&mmio_debug->lock);

	/* Save and disable mmio debugging for the user bypass */
	if (!mmio_debug->suspend_count++) {
		mmio_debug->saved_mmio_check = mmio_debug->unclaimed_mmio_check;
		mmio_debug->unclaimed_mmio_check = 0;
	}
}