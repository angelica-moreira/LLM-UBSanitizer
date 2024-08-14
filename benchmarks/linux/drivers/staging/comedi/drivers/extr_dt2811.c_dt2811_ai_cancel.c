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
struct comedi_subdevice {int dummy; } ;
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
 int /*<<< orphan*/  DT2811_ADCSR_ADMODE (int /*<<< orphan*/ ) ; 
 scalar_t__ DT2811_ADCSR_REG ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int dt2811_ai_cancel(struct comedi_device *dev,
			    struct comedi_subdevice *s)
{
	/*
	 * Mode 0
	 * Single conversion
	 *
	 * Loading a chanspec will trigger a conversion.
	 */
	outb(DT2811_ADCSR_ADMODE(0), dev->iobase + DT2811_ADCSR_REG);

	return 0;
}