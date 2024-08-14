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
typedef  int /*<<< orphan*/  u64 ;
struct nvkm_gr {TYPE_1__* func; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* units ) (struct nvkm_gr*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct nvkm_gr*) ; 

u64
nvkm_gr_units(struct nvkm_gr *gr)
{
	if (gr->func->units)
		return gr->func->units(gr);
	return 0;
}