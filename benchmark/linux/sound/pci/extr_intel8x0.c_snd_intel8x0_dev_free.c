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
struct snd_device {struct intel8x0* device_data; } ;
struct intel8x0 {int dummy; } ;

/* Variables and functions */
 int snd_intel8x0_free (struct intel8x0*) ; 

__attribute__((used)) static int snd_intel8x0_dev_free(struct snd_device *device)
{
	struct intel8x0 *chip = device->device_data;
	return snd_intel8x0_free(chip);
}