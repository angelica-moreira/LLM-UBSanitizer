#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_5__ {int /*<<< orphan*/  IO_ADDR_R; } ;
struct nand_chip {TYPE_1__ legacy; } ;
struct TYPE_6__ {int width; } ;
struct fsl_upm_nand {unsigned int last_ctrl; int* mchip_offsets; size_t mchip_number; int wait_flags; TYPE_2__ upm; int /*<<< orphan*/  upm_cmd_offset; int /*<<< orphan*/  upm_addr_offset; } ;

/* Variables and functions */
 int FSL_UPM_WAIT_RUN_PATTERN ; 
 unsigned int NAND_ALE ; 
 unsigned int NAND_CLE ; 
 int NAND_CMD_NONE ; 
 unsigned int NAND_CTRL_CHANGE ; 
 int /*<<< orphan*/  fsl_upm_end_pattern (TYPE_2__*) ; 
 int /*<<< orphan*/  fsl_upm_run_pattern (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  fsl_upm_start_pattern (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fun_wait_rnb (struct fsl_upm_nand*) ; 
 int /*<<< orphan*/  nand_to_mtd (struct nand_chip*) ; 
 struct fsl_upm_nand* to_fsl_upm_nand (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fun_cmd_ctrl(struct nand_chip *chip, int cmd, unsigned int ctrl)
{
	struct fsl_upm_nand *fun = to_fsl_upm_nand(nand_to_mtd(chip));
	u32 mar;

	if (!(ctrl & fun->last_ctrl)) {
		fsl_upm_end_pattern(&fun->upm);

		if (cmd == NAND_CMD_NONE)
			return;

		fun->last_ctrl = ctrl & (NAND_ALE | NAND_CLE);
	}

	if (ctrl & NAND_CTRL_CHANGE) {
		if (ctrl & NAND_ALE)
			fsl_upm_start_pattern(&fun->upm, fun->upm_addr_offset);
		else if (ctrl & NAND_CLE)
			fsl_upm_start_pattern(&fun->upm, fun->upm_cmd_offset);
	}

	mar = (cmd << (32 - fun->upm.width)) |
		fun->mchip_offsets[fun->mchip_number];
	fsl_upm_run_pattern(&fun->upm, chip->legacy.IO_ADDR_R, mar);

	if (fun->wait_flags & FSL_UPM_WAIT_RUN_PATTERN)
		fun_wait_rnb(fun);
}