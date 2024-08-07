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
struct qlcnic_adapter {TYPE_1__* nic_ops; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int /*<<< orphan*/  (* config_ipaddr ) (struct qlcnic_adapter*,int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct qlcnic_adapter*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void qlcnic_config_ipaddr(struct qlcnic_adapter *adapter,
					__be32 ip, int cmd)
{
	adapter->nic_ops->config_ipaddr(adapter, ip, cmd);
}