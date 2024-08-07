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
struct nvkm_volt {scalar_t__ speedo; TYPE_1__* func; int /*<<< orphan*/  subdev; } ;
struct nvkm_subdev {int dummy; } ;
struct TYPE_2__ {int (* oneinit ) (struct nvkm_volt*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_debug (int /*<<< orphan*/ *,char*,scalar_t__) ; 
 struct nvkm_volt* nvkm_volt (struct nvkm_subdev*) ; 
 scalar_t__ nvkm_volt_speedo_read (struct nvkm_volt*) ; 
 int stub1 (struct nvkm_volt*) ; 

__attribute__((used)) static int
nvkm_volt_oneinit(struct nvkm_subdev *subdev)
{
	struct nvkm_volt *volt = nvkm_volt(subdev);

	volt->speedo = nvkm_volt_speedo_read(volt);
	if (volt->speedo > 0)
		nvkm_debug(&volt->subdev, "speedo %x\n", volt->speedo);

	if (volt->func->oneinit)
		return volt->func->oneinit(volt);

	return 0;
}