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
typedef  void* u8 ;
struct nvkm_i2c_pad {int dummy; } ;
struct nvkm_i2c_bus {int dummy; } ;
struct nv04_i2c_bus {void* sense; void* drive; struct nvkm_i2c_bus base; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nv04_i2c_bus* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nv04_i2c_bus_func ; 
 int /*<<< orphan*/  nvkm_i2c_bus_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_bus*) ; 

int
nv04_i2c_bus_new(struct nvkm_i2c_pad *pad, int id, u8 drive, u8 sense,
		 struct nvkm_i2c_bus **pbus)
{
	struct nv04_i2c_bus *bus;

	if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &bus->base;

	nvkm_i2c_bus_ctor(&nv04_i2c_bus_func, pad, id, &bus->base);
	bus->drive = drive;
	bus->sense = sense;
	return 0;
}