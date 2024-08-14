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
typedef  int u32 ;
struct net_device {int dummy; } ;
struct be_adapter {int msg_enable; } ;

/* Variables and functions */
 scalar_t__ BEx_chip (struct be_adapter*) ; 
 int /*<<< orphan*/  FW_LOG_LEVEL_DEFAULT ; 
 int /*<<< orphan*/  FW_LOG_LEVEL_FATAL ; 
 int NETIF_MSG_HW ; 
 int /*<<< orphan*/  be_cmd_set_fw_log_level (struct be_adapter*,int /*<<< orphan*/ ) ; 
 struct be_adapter* netdev_priv (struct net_device*) ; 

__attribute__((used)) static void be_set_msg_level(struct net_device *netdev, u32 level)
{
	struct be_adapter *adapter = netdev_priv(netdev);

	if (adapter->msg_enable == level)
		return;

	if ((level & NETIF_MSG_HW) != (adapter->msg_enable & NETIF_MSG_HW))
		if (BEx_chip(adapter))
			be_cmd_set_fw_log_level(adapter, level & NETIF_MSG_HW ?
						FW_LOG_LEVEL_DEFAULT :
						FW_LOG_LEVEL_FATAL);
	adapter->msg_enable = level;
}