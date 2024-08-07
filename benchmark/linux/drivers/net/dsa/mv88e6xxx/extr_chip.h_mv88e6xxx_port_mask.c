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
typedef  int /*<<< orphan*/  u16 ;
struct mv88e6xxx_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GENMASK (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ mv88e6xxx_num_ports (struct mv88e6xxx_chip*) ; 

__attribute__((used)) static inline u16 mv88e6xxx_port_mask(struct mv88e6xxx_chip *chip)
{
	return GENMASK(mv88e6xxx_num_ports(chip) - 1, 0);
}