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
typedef  int /*<<< orphan*/  u32 ;
struct nand_chip {int dummy; } ;
struct nand_bbt_descr {int options; int /*<<< orphan*/  veroffs; } ;
struct mtd_info {scalar_t__ writesize; } ;

/* Variables and functions */
 int NAND_BBT_NO_OOB ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 

__attribute__((used)) static u32 bbt_get_ver_offs(struct nand_chip *this, struct nand_bbt_descr *td)
{
	struct mtd_info *mtd = nand_to_mtd(this);
	u32 ver_offs = td->veroffs;

	if (!(td->options & NAND_BBT_NO_OOB))
		ver_offs += mtd->writesize;
	return ver_offs;
}