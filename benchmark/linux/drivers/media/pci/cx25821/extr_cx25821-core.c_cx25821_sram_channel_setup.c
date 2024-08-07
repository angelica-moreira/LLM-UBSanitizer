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
typedef  int u32 ;
struct sram_channel {int cmds_start; unsigned int ptr1_reg; unsigned int ptr2_reg; unsigned int cnt2_reg; unsigned int cnt1_reg; int cdt; unsigned int fifo_size; unsigned int fifo_start; unsigned int ctrl_start; scalar_t__ jumponly; } ;
struct cx25821_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 unsigned int RISC_CNT_INC ; 
 unsigned int RISC_IRQ1 ; 
 unsigned int RISC_JUMP ; 
 int /*<<< orphan*/  cx_write (unsigned int,unsigned int) ; 

int cx25821_sram_channel_setup(struct cx25821_dev *dev,
			       const struct sram_channel *ch,
			       unsigned int bpl, u32 risc)
{
	unsigned int i, lines;
	u32 cdt;

	if (ch->cmds_start == 0) {
		cx_write(ch->ptr1_reg, 0);
		cx_write(ch->ptr2_reg, 0);
		cx_write(ch->cnt2_reg, 0);
		cx_write(ch->cnt1_reg, 0);
		return 0;
	}

	bpl = (bpl + 7) & ~7;	/* alignment */
	cdt = ch->cdt;
	lines = ch->fifo_size / bpl;

	if (lines > 4)
		lines = 4;

	BUG_ON(lines < 2);

	cx_write(8 + 0, RISC_JUMP | RISC_IRQ1 | RISC_CNT_INC);
	cx_write(8 + 4, 8);
	cx_write(8 + 8, 0);

	/* write CDT */
	for (i = 0; i < lines; i++) {
		cx_write(cdt + 16 * i, ch->fifo_start + bpl * i);
		cx_write(cdt + 16 * i + 4, 0);
		cx_write(cdt + 16 * i + 8, 0);
		cx_write(cdt + 16 * i + 12, 0);
	}

	/* init the first cdt buffer */
	for (i = 0; i < 128; i++)
		cx_write(ch->fifo_start + 4 * i, i);

	/* write CMDS */
	if (ch->jumponly)
		cx_write(ch->cmds_start + 0, 8);
	else
		cx_write(ch->cmds_start + 0, risc);

	cx_write(ch->cmds_start + 4, 0);	/* 64 bits 63-32 */
	cx_write(ch->cmds_start + 8, cdt);
	cx_write(ch->cmds_start + 12, (lines * 16) >> 3);
	cx_write(ch->cmds_start + 16, ch->ctrl_start);

	if (ch->jumponly)
		cx_write(ch->cmds_start + 20, 0x80000000 | (64 >> 2));
	else
		cx_write(ch->cmds_start + 20, 64 >> 2);

	for (i = 24; i < 80; i += 4)
		cx_write(ch->cmds_start + i, 0);

	/* fill registers */
	cx_write(ch->ptr1_reg, ch->fifo_start);
	cx_write(ch->ptr2_reg, cdt);
	cx_write(ch->cnt2_reg, (lines * 16) >> 3);
	cx_write(ch->cnt1_reg, (bpl >> 3) - 1);

	return 0;
}