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
struct nvkm_subdev {int dummy; } ;
struct nvkm_bar {TYPE_2__* func; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* wait ) (struct nvkm_bar*) ;int /*<<< orphan*/  (* init ) (struct nvkm_bar*) ;} ;
struct TYPE_4__ {int /*<<< orphan*/  (* init ) (struct nvkm_bar*) ;TYPE_1__ bar1; } ;

/* Variables and functions */
 struct nvkm_bar* nvkm_bar (struct nvkm_subdev*) ; 
 int /*<<< orphan*/  stub1 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub2 (struct nvkm_bar*) ; 
 int /*<<< orphan*/  stub3 (struct nvkm_bar*) ; 

__attribute__((used)) static int
nvkm_bar_init(struct nvkm_subdev *subdev)
{
	struct nvkm_bar *bar = nvkm_bar(subdev);
	bar->func->bar1.init(bar);
	bar->func->bar1.wait(bar);
	if (bar->func->init)
		bar->func->init(bar);
	return 0;
}