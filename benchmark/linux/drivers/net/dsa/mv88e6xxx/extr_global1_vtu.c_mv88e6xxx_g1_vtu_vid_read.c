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
typedef  int u16 ;
struct mv88e6xxx_vtu_entry {int vid; int valid; } ;
struct mv88e6xxx_chip {int dummy; } ;

/* Variables and functions */
 int MV88E6390_G1_VTU_VID_PAGE ; 
 int /*<<< orphan*/  MV88E6XXX_G1_VTU_VID ; 
 int MV88E6XXX_G1_VTU_VID_VALID ; 
 int mv88e6xxx_g1_read (struct mv88e6xxx_chip*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int mv88e6xxx_g1_vtu_vid_read(struct mv88e6xxx_chip *chip,
				     struct mv88e6xxx_vtu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_VID, &val);
	if (err)
		return err;

	entry->vid = val & 0xfff;

	if (val & MV88E6390_G1_VTU_VID_PAGE)
		entry->vid |= 0x1000;

	entry->valid = !!(val & MV88E6XXX_G1_VTU_VID_VALID);

	return 0;
}