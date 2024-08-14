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
struct snd_riptide {int dummy; } ;
struct snd_device {struct snd_riptide* device_data; } ;

/* Variables and functions */
 int snd_riptide_free (struct snd_riptide*) ; 

__attribute__((used)) static int snd_riptide_dev_free(struct snd_device *device)
{
	struct snd_riptide *chip = device->device_data;

	return snd_riptide_free(chip);
}