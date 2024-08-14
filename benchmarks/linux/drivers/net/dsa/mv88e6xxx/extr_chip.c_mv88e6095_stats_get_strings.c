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
typedef  int /*<<< orphan*/  uint8_t ;
struct mv88e6xxx_chip {int dummy; } ;

/* Variables and functions */
 int STATS_TYPE_BANK0 ; 
 int STATS_TYPE_PORT ; 
 int mv88e6xxx_stats_get_strings (struct mv88e6xxx_chip*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int mv88e6095_stats_get_strings(struct mv88e6xxx_chip *chip,
				       uint8_t *data)
{
	return mv88e6xxx_stats_get_strings(chip, data,
					   STATS_TYPE_BANK0 | STATS_TYPE_PORT);
}