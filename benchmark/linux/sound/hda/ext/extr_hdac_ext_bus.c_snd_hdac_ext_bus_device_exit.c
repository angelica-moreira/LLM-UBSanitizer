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
struct hdac_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_hdac_device_exit (struct hdac_device*) ; 

void snd_hdac_ext_bus_device_exit(struct hdac_device *hdev)
{
	snd_hdac_device_exit(hdev);
}