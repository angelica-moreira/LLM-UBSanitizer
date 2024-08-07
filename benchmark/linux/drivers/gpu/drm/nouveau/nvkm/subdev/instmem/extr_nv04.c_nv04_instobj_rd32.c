#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct nvkm_memory {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nv04_instobj {TYPE_4__* node; TYPE_3__* imem; } ;
struct TYPE_8__ {scalar_t__ offset; } ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct TYPE_6__ {TYPE_1__ subdev; } ;
struct TYPE_7__ {TYPE_2__ base; } ;

/* Variables and functions */
 struct nv04_instobj* nv04_instobj (struct nvkm_memory*) ; 
 int /*<<< orphan*/  nvkm_rd32 (struct nvkm_device*,scalar_t__) ; 

__attribute__((used)) static u32
nv04_instobj_rd32(struct nvkm_memory *memory, u64 offset)
{
	struct nv04_instobj *iobj = nv04_instobj(memory);
	struct nvkm_device *device = iobj->imem->base.subdev.device;
	return nvkm_rd32(device, 0x700000 + iobj->node->offset + offset);
}