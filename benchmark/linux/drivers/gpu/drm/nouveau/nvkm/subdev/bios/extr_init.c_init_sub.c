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
typedef  int /*<<< orphan*/  u8 ;
typedef  void* u16 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_init {void* offset; TYPE_2__* subdev; } ;
struct TYPE_4__ {TYPE_1__* device; } ;
struct TYPE_3__ {struct nvkm_bios* bios; } ;

/* Variables and functions */
 int /*<<< orphan*/  error (char*) ; 
 scalar_t__ init_exec (struct nvbios_init*) ; 
 void* init_script (struct nvkm_bios*,int /*<<< orphan*/ ) ; 
 scalar_t__ nvbios_exec (struct nvbios_init*) ; 
 int /*<<< orphan*/  nvbios_rd08 (struct nvkm_bios*,void*) ; 
 int /*<<< orphan*/  trace (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
init_sub(struct nvbios_init *init)
{
	struct nvkm_bios *bios = init->subdev->device->bios;
	u8 index = nvbios_rd08(bios, init->offset + 1);
	u16 addr, save;

	trace("SUB\t0x%02x\n", index);

	addr = init_script(bios, index);
	if (addr && init_exec(init)) {
		save = init->offset;
		init->offset = addr;
		if (nvbios_exec(init)) {
			error("error parsing sub-table\n");
			return;
		}
		init->offset = save;
	}

	init->offset += 2;
}