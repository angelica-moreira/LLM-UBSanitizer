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

/* Variables and functions */
 int /*<<< orphan*/  __clear_bit (int,unsigned long*) ; 
 unsigned long superio_inb (int,int) ; 
 int /*<<< orphan*/  superio_outb (int,int,unsigned long) ; 

__attribute__((used)) static inline void superio_clear_bit(int base, int reg, int bit)
{
	unsigned long val = superio_inb(base, reg);
	__clear_bit(bit, &val);
	superio_outb(base, reg, val);
}