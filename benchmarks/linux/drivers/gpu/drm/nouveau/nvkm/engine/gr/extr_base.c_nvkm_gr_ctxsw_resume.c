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
struct nvkm_gr {TYPE_2__* func; } ;
struct nvkm_device {struct nvkm_gr* gr; } ;
struct TYPE_3__ {int (* resume ) (struct nvkm_gr*) ;} ;
struct TYPE_4__ {TYPE_1__ ctxsw; } ;

/* Variables and functions */
 int stub1 (struct nvkm_gr*) ; 

int
nvkm_gr_ctxsw_resume(struct nvkm_device *device)
{
	struct nvkm_gr *gr = device->gr;
	if (gr && gr->func->ctxsw.resume)
		return gr->func->ctxsw.resume(gr);
	return 0;
}