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
struct nvkm_msgqueue {TYPE_1__* func; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* dtor ) (struct nvkm_msgqueue*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct nvkm_msgqueue*) ; 

void
nvkm_msgqueue_del(struct nvkm_msgqueue **queue)
{
	if (*queue) {
		(*queue)->func->dtor(*queue);
		*queue = NULL;
	}
}