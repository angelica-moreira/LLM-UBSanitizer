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
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_mask (struct nvkm_device*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
gf100_ibus_init(struct nvkm_subdev *ibus)
{
	struct nvkm_device *device = ibus->device;
	nvkm_mask(device, 0x122310, 0x0003ffff, 0x00000800);
	nvkm_wr32(device, 0x12232c, 0x00100064);
	nvkm_wr32(device, 0x122330, 0x00100064);
	nvkm_wr32(device, 0x122334, 0x00100064);
	nvkm_mask(device, 0x122348, 0x0003ffff, 0x00000100);
	return 0;
}