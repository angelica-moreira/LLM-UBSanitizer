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
struct nand_chip {int dummy; } ;

/* Variables and functions */
 int meson_nfc_read_page_raw (struct nand_chip*,int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static int meson_nfc_read_oob_raw(struct nand_chip *nand, int page)
{
	return meson_nfc_read_page_raw(nand, NULL, 1, page);
}