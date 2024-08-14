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
struct xfs_efi_log_item {int /*<<< orphan*/  efi_item; int /*<<< orphan*/  efi_refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  SHUTDOWN_LOG_IO_ERROR ; 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xfs_efi_item_free (struct xfs_efi_log_item*) ; 
 int /*<<< orphan*/  xfs_trans_ail_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void
xfs_efi_release(
	struct xfs_efi_log_item	*efip)
{
	ASSERT(atomic_read(&efip->efi_refcount) > 0);
	if (atomic_dec_and_test(&efip->efi_refcount)) {
		xfs_trans_ail_remove(&efip->efi_item, SHUTDOWN_LOG_IO_ERROR);
		xfs_efi_item_free(efip);
	}
}