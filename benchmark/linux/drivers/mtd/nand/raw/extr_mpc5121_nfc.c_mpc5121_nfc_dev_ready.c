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

__attribute__((used)) static int mpc5121_nfc_dev_ready(struct nand_chip *nand)
{
	/*
	 * NFC handles ready/busy signal internally. Therefore, this function
	 * always returns status as ready.
	 */
	return 1;
}