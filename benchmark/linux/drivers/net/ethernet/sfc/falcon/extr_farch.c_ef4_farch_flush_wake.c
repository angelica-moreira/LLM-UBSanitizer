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
struct ef4_nic {int /*<<< orphan*/  rxq_flush_pending; int /*<<< orphan*/  rxq_flush_outstanding; int /*<<< orphan*/  active_queues; } ;

/* Variables and functions */
 scalar_t__ EF4_RX_FLUSH_COUNT ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  smp_mb () ; 

__attribute__((used)) static bool ef4_farch_flush_wake(struct ef4_nic *efx)
{
	/* Ensure that all updates are visible to ef4_farch_flush_queues() */
	smp_mb();

	return (atomic_read(&efx->active_queues) == 0 ||
		(atomic_read(&efx->rxq_flush_outstanding) < EF4_RX_FLUSH_COUNT
		 && atomic_read(&efx->rxq_flush_pending) > 0));
}