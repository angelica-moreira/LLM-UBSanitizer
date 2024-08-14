#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  mmio; } ;
typedef  TYPE_1__ vortex_t ;
struct TYPE_5__ {int slice; scalar_t__ vortex; } ;
typedef  TYPE_2__ a3dsrc_t ;

/* Variables and functions */
 scalar_t__ A3D_SLICE_Control ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,scalar_t__,int) ; 

__attribute__((used)) static void a3dsrc_EnableA3D(a3dsrc_t * a)
{
	vortex_t *vortex = (vortex_t *) (a->vortex);
	hwwrite(vortex->mmio, A3D_SLICE_Control + ((a->slice) << 0xd),
		0xF0000001);
	//hwwrite(vortex->mmio, 0x19C38 + (this08<<0xd), 0xF0000001);
}