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
struct nand_chip {int /*<<< orphan*/ * oob_poi; } ;

/* Variables and functions */
 int denali_write_raw (struct nand_chip*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int denali_write_page_raw(struct nand_chip *chip, const u8 *buf,
				 int oob_required, int page)
{
	return denali_write_raw(chip, buf, oob_required ? chip->oob_poi : NULL,
				page);
}