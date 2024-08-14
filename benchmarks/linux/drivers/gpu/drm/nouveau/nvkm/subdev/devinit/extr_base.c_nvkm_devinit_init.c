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
struct nvkm_subdev {int dummy; } ;
struct nvkm_devinit {TYPE_1__* func; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* init ) (struct nvkm_devinit*) ;} ;

/* Variables and functions */
 struct nvkm_devinit* nvkm_devinit (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_devinit*) ; 

__attribute__((used)) static int
nvkm_devinit_init(struct nvkm_subdev *subdev)
{
	struct nvkm_devinit *init = nvkm_devinit(subdev);
	if (init->func->init)
		init->func->init(init);
	return 0;
}