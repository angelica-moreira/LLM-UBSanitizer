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
struct oxygen {scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  inw (scalar_t__) ; 

u16 oxygen_read16(struct oxygen *chip, unsigned int reg)
{
	return inw(chip->addr + reg);
}