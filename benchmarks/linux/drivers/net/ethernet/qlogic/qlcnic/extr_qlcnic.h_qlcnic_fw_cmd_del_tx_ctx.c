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
struct qlcnic_host_tx_ring {int dummy; } ;
struct qlcnic_adapter {TYPE_2__* ahw; } ;
struct TYPE_4__ {TYPE_1__* hw_ops; } ;
struct TYPE_3__ {void (* del_tx_ctx ) (struct qlcnic_adapter*,struct qlcnic_host_tx_ring*) ;} ;

/* Variables and functions */
 void stub1 (struct qlcnic_adapter*,struct qlcnic_host_tx_ring*) ; 

__attribute__((used)) static inline void qlcnic_fw_cmd_del_tx_ctx(struct qlcnic_adapter *adapter,
					    struct qlcnic_host_tx_ring *ptr)
{
	return adapter->ahw->hw_ops->del_tx_ctx(adapter, ptr);
}