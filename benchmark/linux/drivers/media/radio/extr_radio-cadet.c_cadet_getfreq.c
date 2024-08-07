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
struct cadet {int /*<<< orphan*/  is_fm_band; } ;

/* Variables and functions */
 unsigned int cadet_gettune (struct cadet*) ; 

__attribute__((used)) static unsigned cadet_getfreq(struct cadet *dev)
{
	int i;
	unsigned freq = 0, test, fifo = 0;

	/*
	 * Read current tuning
	 */
	fifo = cadet_gettune(dev);

	/*
	 * Convert to actual frequency
	 */
	if (!dev->is_fm_band)    /* AM */
		return ((fifo & 0x7fff) - 450) * 16;

	test = 12500;
	for (i = 0; i < 14; i++) {
		if ((fifo & 0x01) != 0)
			freq += test;
		test = test << 1;
		fifo = fifo >> 1;
	}
	freq -= 10700000;           /* IF frequency is 10.7 MHz */
	freq = (freq * 16) / 1000;   /* Make it 1/16 kHz */
	return freq;
}