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
struct nand_chip {int dummy; } ;
struct mtd_info {int /*<<< orphan*/  writesize; } ;

/* Variables and functions */
 int denali_page_xfer (struct nand_chip*,void*,int /*<<< orphan*/ ,int,int) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 

__attribute__((used)) static int denali_write_page(struct nand_chip *chip, const u8 *buf,
			     int oob_required, int page)
{
	struct mtd_info *mtd = nand_to_mtd(chip);

	return denali_page_xfer(chip, (void *)buf, mtd->writesize, page, true);
}