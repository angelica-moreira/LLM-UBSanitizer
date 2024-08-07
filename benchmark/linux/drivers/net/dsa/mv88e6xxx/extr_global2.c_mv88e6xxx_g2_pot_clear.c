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
struct mv88e6xxx_chip {int dummy; } ;

/* Variables and functions */
 int mv88e6xxx_g2_pot_write (struct mv88e6xxx_chip*,int,int /*<<< orphan*/ ) ; 

int mv88e6xxx_g2_pot_clear(struct mv88e6xxx_chip *chip)
{
	int i, err;

	/* Clear all sixteen possible Priority Override entries */
	for (i = 0; i < 16; i++) {
		err = mv88e6xxx_g2_pot_write(chip, i, 0);
		if (err)
			break;
	}

	return err;
}