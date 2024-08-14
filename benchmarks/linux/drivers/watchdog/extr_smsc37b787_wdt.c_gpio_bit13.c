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
 int /*<<< orphan*/  write_io_cr (int,unsigned char) ; 

__attribute__((used)) static inline void gpio_bit13(unsigned char reg)
{
	/* -- General Purpose I/O Bit 1.3 --
	 * Bit 0,  In/Out: 0 = Output, 1 = Input
	 * Bit 1,  Polarity: 0 = No Invert, 1 = Invert
	 * Bit 2,  Group Enable Intr.: 0 = Disable, 1 = Enable
	 * Bit 3,  Function select: 0 = GPI/O, 1 = LED
	 * Bit 4-6 (Reserved)
	 * Bit 7,  Output Type: 0 = Push Pull Bit, 1 = Open Drain
	 */
	write_io_cr(0xE3, reg);
}