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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u64 ;
struct vnic_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_GET_MAC_ADDR ; 
 int ETH_ALEN ; 
 int vnic_dev_cmd (struct vnic_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

int vnic_dev_get_mac_addr(struct vnic_dev *vdev, u8 *mac_addr)
{
	u64 a0, a1;
	int wait = 1000;
	int err, i;

	for (i = 0; i < ETH_ALEN; i++)
		mac_addr[i] = 0;

	err = vnic_dev_cmd(vdev, CMD_GET_MAC_ADDR, &a0, &a1, wait);
	if (err)
		return err;

	for (i = 0; i < ETH_ALEN; i++)
		mac_addr[i] = ((u8 *)&a0)[i];

	return 0;
}