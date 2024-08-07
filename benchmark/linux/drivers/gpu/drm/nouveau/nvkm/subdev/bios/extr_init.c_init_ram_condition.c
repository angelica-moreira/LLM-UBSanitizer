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
typedef  int u8 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_init {scalar_t__ offset; TYPE_2__* subdev; } ;
struct TYPE_4__ {TYPE_1__* device; } ;
struct TYPE_3__ {struct nvkm_bios* bios; } ;

/* Variables and functions */
 int /*<<< orphan*/  init_exec_set (struct nvbios_init*,int) ; 
 int init_rd32 (struct nvbios_init*,int) ; 
 int nvbios_rd08 (struct nvkm_bios*,scalar_t__) ; 
 int /*<<< orphan*/  trace (char*,int,int) ; 

__attribute__((used)) static void
init_ram_condition(struct nvbios_init *init)
{
	struct nvkm_bios *bios = init->subdev->device->bios;
	u8  mask = nvbios_rd08(bios, init->offset + 1);
	u8 value = nvbios_rd08(bios, init->offset + 2);

	trace("RAM_CONDITION\t"
	      "(R[0x100000] & 0x%02x) == 0x%02x\n", mask, value);
	init->offset += 3;

	if ((init_rd32(init, 0x100000) & mask) != value)
		init_exec_set(init, false);
}