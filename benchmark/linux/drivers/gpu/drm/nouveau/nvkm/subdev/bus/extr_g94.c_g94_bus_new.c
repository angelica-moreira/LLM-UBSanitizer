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
struct nvkm_device {int dummy; } ;
struct nvkm_bus {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  g94_bus ; 
 int nvkm_bus_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_bus**) ; 

int
g94_bus_new(struct nvkm_device *device, int index, struct nvkm_bus **pbus)
{
	return nvkm_bus_new_(&g94_bus, device, index, pbus);
}