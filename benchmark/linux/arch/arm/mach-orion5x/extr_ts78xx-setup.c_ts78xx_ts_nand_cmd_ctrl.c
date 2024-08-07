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
struct TYPE_2__ {int /*<<< orphan*/  IO_ADDR_W; } ;
struct nand_chip {TYPE_1__ legacy; } ;

/* Variables and functions */
 unsigned int NAND_ALE ; 
 unsigned int NAND_CLE ; 
 int NAND_CMD_NONE ; 
 unsigned int NAND_CTRL_CHANGE ; 
 unsigned int NAND_NCE ; 
 int /*<<< orphan*/  TS_NAND_CTRL ; 
 int readb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writeb (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ts78xx_ts_nand_cmd_ctrl(struct nand_chip *this, int cmd,
				    unsigned int ctrl)
{
	if (ctrl & NAND_CTRL_CHANGE) {
		unsigned char bits;

		bits = (ctrl & NAND_NCE) << 2;
		bits |= ctrl & NAND_CLE;
		bits |= (ctrl & NAND_ALE) >> 2;

		writeb((readb(TS_NAND_CTRL) & ~0x7) | bits, TS_NAND_CTRL);
	}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, this->legacy.IO_ADDR_W);
}