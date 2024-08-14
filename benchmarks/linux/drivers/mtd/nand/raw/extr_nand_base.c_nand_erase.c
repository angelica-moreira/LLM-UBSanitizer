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
struct mtd_info {int dummy; } ;
struct erase_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mtd_to_nand (struct mtd_info*) ; 
 int nand_erase_nand (int /*<<< orphan*/ ,struct erase_info*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int nand_erase(struct mtd_info *mtd, struct erase_info *instr)
{
	return nand_erase_nand(mtd_to_nand(mtd), instr, 0);
}