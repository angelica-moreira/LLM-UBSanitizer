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
typedef  int /*<<< orphan*/  u8 ;
struct enic {int /*<<< orphan*/  devcmd_lock; int /*<<< orphan*/  vdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int vnic_dev_add_addr (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 

int enic_dev_add_addr(struct enic *enic, const u8 *addr)
{
	int err;

	spin_lock_bh(&enic->devcmd_lock);
	err = vnic_dev_add_addr(enic->vdev, addr);
	spin_unlock_bh(&enic->devcmd_lock);

	return err;
}