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
typedef  int /*<<< orphan*/  uint32_t ;
struct fw_bye_cmd {void* retval_len16; void* op_to_write; } ;
struct csio_mb {scalar_t__ mb; } ;
struct csio_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CSIO_INIT_MBP (struct csio_mb*,struct fw_bye_cmd*,int /*<<< orphan*/ ,struct csio_hw*,void (*) (struct csio_hw*,struct csio_mb*),int) ; 
 int /*<<< orphan*/  FW_BYE_CMD ; 
 int FW_CMD_LEN16_V (int) ; 
 int FW_CMD_OP_V (int /*<<< orphan*/ ) ; 
 int FW_CMD_REQUEST_F ; 
 int FW_CMD_WRITE_F ; 
 void* htonl (int) ; 

void
csio_mb_bye(struct csio_hw *hw, struct csio_mb *mbp, uint32_t tmo,
	    void (*cbfn) (struct csio_hw *, struct csio_mb *))
{
	struct fw_bye_cmd *cmdp = (struct fw_bye_cmd *)(mbp->mb);

	CSIO_INIT_MBP(mbp, cmdp, tmo, hw, cbfn, 1);

	cmdp->op_to_write = htonl(FW_CMD_OP_V(FW_BYE_CMD) |
				       FW_CMD_REQUEST_F | FW_CMD_WRITE_F);
	cmdp->retval_len16 = htonl(FW_CMD_LEN16_V(sizeof(*cmdp) / 16));

}