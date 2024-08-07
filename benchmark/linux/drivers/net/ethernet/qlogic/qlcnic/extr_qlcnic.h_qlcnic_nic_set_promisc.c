#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct qlcnic_adapter {TYPE_2__* ahw; } ;
struct TYPE_4__ {TYPE_1__* hw_ops; } ;
struct TYPE_3__ {int (* config_promisc_mode ) (struct qlcnic_adapter*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct qlcnic_adapter*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int qlcnic_nic_set_promisc(struct qlcnic_adapter *adapter,
					 u32 mode)
{
	return adapter->ahw->hw_ops->config_promisc_mode(adapter, mode);
}