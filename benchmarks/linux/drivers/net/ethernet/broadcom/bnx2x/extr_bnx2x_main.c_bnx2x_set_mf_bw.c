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
struct bnx2x {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_MSG_CODE_SET_MF_BW_ACK ; 
 int /*<<< orphan*/  bnx2x_config_mf_bw (struct bnx2x*) ; 
 int /*<<< orphan*/  bnx2x_fw_command (struct bnx2x*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bnx2x_set_mf_bw(struct bnx2x *bp)
{
	bnx2x_config_mf_bw(bp);
	bnx2x_fw_command(bp, DRV_MSG_CODE_SET_MF_BW_ACK, 0);
}