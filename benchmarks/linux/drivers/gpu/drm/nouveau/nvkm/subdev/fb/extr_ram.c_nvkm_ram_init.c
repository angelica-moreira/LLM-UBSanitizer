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
struct nvkm_ram {TYPE_1__* func; } ;
struct TYPE_2__ {int (* init ) (struct nvkm_ram*) ;} ;

/* Variables and functions */
 int stub1 (struct nvkm_ram*) ; 

int
nvkm_ram_init(struct nvkm_ram *ram)
{
	if (ram->func->init)
		return ram->func->init(ram);
	return 0;
}