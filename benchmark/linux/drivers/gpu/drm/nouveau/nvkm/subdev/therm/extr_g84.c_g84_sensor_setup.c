#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {struct nvkm_device* device; } ;
struct nvkm_therm {TYPE_1__ subdev; } ;
struct nvkm_device {int /*<<< orphan*/  fuse; } ;

/* Variables and functions */
 int /*<<< orphan*/  mdelay (int) ; 
 int nvkm_fuse_read (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 

void
g84_sensor_setup(struct nvkm_therm *therm)
{
	struct nvkm_device *device = therm->subdev.device;

	/* enable temperature reading for cards with insane defaults */
	if (nvkm_fuse_read(device->fuse, 0x1a8) == 1) {
		nvkm_mask(device, 0x20008, 0x80008000, 0x80000000);
		nvkm_mask(device, 0x2000c, 0x80000003, 0x00000000);
		mdelay(20); /* wait for the temperature to stabilize */
	}
}