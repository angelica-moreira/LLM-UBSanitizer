#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/ * dev_ready; } ;
struct nand_chip {TYPE_2__ legacy; } ;
struct atmel_nand {int numcs; TYPE_3__* activecs; TYPE_3__* cs; } ;
struct TYPE_4__ {scalar_t__ type; } ;
struct TYPE_6__ {TYPE_1__ rb; } ;

/* Variables and functions */
 scalar_t__ ATMEL_NAND_GPIO_RB ; 
 int /*<<< orphan*/ * atmel_nand_dev_ready ; 
 struct atmel_nand* to_atmel_nand (struct nand_chip*) ; 

__attribute__((used)) static void atmel_nand_select_chip(struct nand_chip *chip, int cs)
{
	struct atmel_nand *nand = to_atmel_nand(chip);

	if (cs < 0 || cs >= nand->numcs) {
		nand->activecs = NULL;
		chip->legacy.dev_ready = NULL;
		return;
	}

	nand->activecs = &nand->cs[cs];

	if (nand->activecs->rb.type == ATMEL_NAND_GPIO_RB)
		chip->legacy.dev_ready = atmel_nand_dev_ready;
}