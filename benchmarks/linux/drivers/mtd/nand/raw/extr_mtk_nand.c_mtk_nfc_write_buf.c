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

/* Variables and functions */
 int /*<<< orphan*/  mtk_nfc_write_byte (struct nand_chip*,int /*<<< orphan*/  const) ; 

__attribute__((used)) static void mtk_nfc_write_buf(struct nand_chip *chip, const u8 *buf, int len)
{
	int i;

	for (i = 0; i < len; i++)
		mtk_nfc_write_byte(chip, buf[i]);
}