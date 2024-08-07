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
struct slave {int dummy; } ;
struct bonding {int /*<<< orphan*/  mode_lock; } ;

/* Variables and functions */
 struct slave* __tlb_choose_channel (struct bonding*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct slave *tlb_choose_channel(struct bonding *bond, u32 hash_index,
					u32 skb_len)
{
	struct slave *tx_slave;

	/* We don't need to disable softirq here, becase
	 * tlb_choose_channel() is only called by bond_alb_xmit()
	 * which already has softirq disabled.
	 */
	spin_lock(&bond->mode_lock);
	tx_slave = __tlb_choose_channel(bond, hash_index, skb_len);
	spin_unlock(&bond->mode_lock);

	return tx_slave;
}