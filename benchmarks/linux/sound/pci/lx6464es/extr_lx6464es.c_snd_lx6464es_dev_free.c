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
struct snd_device {int /*<<< orphan*/  device_data; } ;

/* Variables and functions */
 int snd_lx6464es_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_lx6464es_dev_free(struct snd_device *device)
{
	return snd_lx6464es_free(device->device_data);
}