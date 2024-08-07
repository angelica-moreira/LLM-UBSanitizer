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
typedef  int /*<<< orphan*/  uint64_t ;
struct qla_hw_data {int dummy; } ;
struct fc_port {TYPE_1__* vha; } ;
struct TYPE_2__ {struct qla_hw_data* hw; } ;

/* Variables and functions */
 scalar_t__ IS_FWI2_CAPABLE (struct qla_hw_data*) ; 
 int /*<<< orphan*/  TCF_TARGET_RESET ; 
 int __qla24xx_issue_tmf (char*,int /*<<< orphan*/ ,struct fc_port*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ ql2xasynctmfenable ; 
 int qla2x00_async_tm_cmd (struct fc_port*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int
qla24xx_abort_target(struct fc_port *fcport, uint64_t l, int tag)
{
	struct qla_hw_data *ha = fcport->vha->hw;

	if ((ql2xasynctmfenable) && IS_FWI2_CAPABLE(ha))
		return qla2x00_async_tm_cmd(fcport, TCF_TARGET_RESET, l, tag);

	return __qla24xx_issue_tmf("Target", TCF_TARGET_RESET, fcport, l, tag);
}