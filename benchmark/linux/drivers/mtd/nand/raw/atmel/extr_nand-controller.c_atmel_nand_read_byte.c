#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct nand_chip {int dummy; } ;
struct atmel_nand {TYPE_2__* activecs; } ;
struct TYPE_3__ {int /*<<< orphan*/  virt; } ;
struct TYPE_4__ {TYPE_1__ io; } ;

/* Variables and functions */
 int /*<<< orphan*/  ioread8 (int /*<<< orphan*/ ) ; 
 struct atmel_nand* to_atmel_nand (struct nand_chip*) ; 

__attribute__((used)) static u8 atmel_nand_read_byte(struct nand_chip *chip)
{
	struct atmel_nand *nand = to_atmel_nand(chip);

	return ioread8(nand->activecs->io.virt);
}