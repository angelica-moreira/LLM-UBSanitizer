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
struct TYPE_2__ {int /*<<< orphan*/ * arg; } ;
struct qlcnic_cmd_args {TYPE_1__ rsp; } ;
struct qlcnic_adapter {int rx_pvid; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int MSW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QLCNIC_TAGGING_ENABLED ; 

__attribute__((used)) static int qlcnic_sriov_set_pvid_mode(struct qlcnic_adapter *adapter,
				      struct qlcnic_cmd_args *cmd)
{
	adapter->rx_pvid = MSW(cmd->rsp.arg[1]) & 0xffff;
	adapter->flags &= ~QLCNIC_TAGGING_ENABLED;
	return 0;
}