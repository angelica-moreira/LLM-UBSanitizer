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
typedef  int /*<<< orphan*/  u8 ;
struct nand_chip {int /*<<< orphan*/  oob_poi; } ;
struct mtd_info {int /*<<< orphan*/  oobsize; int /*<<< orphan*/  writesize; } ;

/* Variables and functions */
 int nand_change_write_column_op (struct nand_chip*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nand_prog_page_end_op (struct nand_chip*) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 
 int /*<<< orphan*/  stm32_fmc2_rw_page_init (struct nand_chip*,int,int,int) ; 
 int stm32_fmc2_xfer (struct nand_chip*,int /*<<< orphan*/  const*,int,int) ; 

__attribute__((used)) static int stm32_fmc2_sequencer_write(struct nand_chip *chip,
				      const u8 *buf, int oob_required,
				      int page, int raw)
{
	struct mtd_info *mtd = nand_to_mtd(chip);
	int ret;

	/* Configure the sequencer */
	stm32_fmc2_rw_page_init(chip, page, raw, true);

	/* Write the page */
	ret = stm32_fmc2_xfer(chip, buf, raw, true);
	if (ret)
		return ret;

	/* Write oob */
	if (oob_required) {
		ret = nand_change_write_column_op(chip, mtd->writesize,
						  chip->oob_poi, mtd->oobsize,
						  false);
		if (ret)
			return ret;
	}

	return nand_prog_page_end_op(chip);
}