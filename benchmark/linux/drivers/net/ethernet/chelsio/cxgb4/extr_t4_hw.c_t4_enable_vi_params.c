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
struct fw_vi_enable_cmd {void* ien_to_len16; void* op_to_viid; } ;
struct adapter {int dummy; } ;
typedef  int /*<<< orphan*/  c ;

/* Variables and functions */
 int FW_CMD_EXEC_F ; 
 int FW_CMD_OP_V (int /*<<< orphan*/ ) ; 
 int FW_CMD_REQUEST_F ; 
 int FW_LEN16 (struct fw_vi_enable_cmd) ; 
 int /*<<< orphan*/  FW_VI_ENABLE_CMD ; 
 int FW_VI_ENABLE_CMD_DCB_INFO_V (int) ; 
 int FW_VI_ENABLE_CMD_EEN_V (int) ; 
 int FW_VI_ENABLE_CMD_IEN_V (int) ; 
 int FW_VI_ENABLE_CMD_VIID_V (unsigned int) ; 
 void* cpu_to_be32 (int) ; 
 int /*<<< orphan*/  memset (struct fw_vi_enable_cmd*,int /*<<< orphan*/ ,int) ; 
 int t4_wr_mbox_ns (struct adapter*,unsigned int,struct fw_vi_enable_cmd*,int,int /*<<< orphan*/ *) ; 

int t4_enable_vi_params(struct adapter *adap, unsigned int mbox,
			unsigned int viid, bool rx_en, bool tx_en, bool dcb_en)
{
	struct fw_vi_enable_cmd c;

	memset(&c, 0, sizeof(c));
	c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_ENABLE_CMD) |
				   FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
				   FW_VI_ENABLE_CMD_VIID_V(viid));
	c.ien_to_len16 = cpu_to_be32(FW_VI_ENABLE_CMD_IEN_V(rx_en) |
				     FW_VI_ENABLE_CMD_EEN_V(tx_en) |
				     FW_VI_ENABLE_CMD_DCB_INFO_V(dcb_en) |
				     FW_LEN16(c));
	return t4_wr_mbox_ns(adap, mbox, &c, sizeof(c), NULL);
}