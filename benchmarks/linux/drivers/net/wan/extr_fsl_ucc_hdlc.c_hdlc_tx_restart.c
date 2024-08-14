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
struct ucc_hdlc_private {TYPE_2__* ut_info; } ;
struct TYPE_3__ {int /*<<< orphan*/  ucc_num; } ;
struct TYPE_4__ {TYPE_1__ uf_info; } ;

/* Variables and functions */
 int /*<<< orphan*/  QE_CR_PROTOCOL_UNSPECIFIED ; 
 int /*<<< orphan*/  QE_RESTART_TX ; 
 int /*<<< orphan*/  qe_issue_cmd (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ucc_fast_get_qe_cr_subblock (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hdlc_tx_restart(struct ucc_hdlc_private *priv)
{
	u32 cecr_subblock;

	cecr_subblock =
		ucc_fast_get_qe_cr_subblock(priv->ut_info->uf_info.ucc_num);

	qe_issue_cmd(QE_RESTART_TX, cecr_subblock,
		     QE_CR_PROTOCOL_UNSPECIFIED, 0);
	return 0;
}