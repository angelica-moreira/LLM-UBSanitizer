#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_3__ {struct nvkm_device* device; } ;
struct TYPE_4__ {TYPE_1__ subdev; } ;
struct nvkm_pm {TYPE_2__ engine; } ;
struct nvkm_perfdom {int mode; scalar_t__ addr; } ;
struct nvkm_perfctr {int logic_op; int* signal; int slot; } ;
struct nvkm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,scalar_t__,int) ; 

__attribute__((used)) static void
gf100_perfctr_init(struct nvkm_pm *pm, struct nvkm_perfdom *dom,
		   struct nvkm_perfctr *ctr)
{
	struct nvkm_device *device = pm->engine.subdev.device;
	u32 log = ctr->logic_op;
	u32 src = 0x00000000;
	int i;

	for (i = 0; i < 4; i++)
		src |= ctr->signal[i] << (i * 8);

	nvkm_wr32(device, dom->addr + 0x09c, 0x00040002 | (dom->mode << 3));
	nvkm_wr32(device, dom->addr + 0x100, 0x00000000);
	nvkm_wr32(device, dom->addr + 0x040 + (ctr->slot * 0x08), src);
	nvkm_wr32(device, dom->addr + 0x044 + (ctr->slot * 0x08), log);
}