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
struct TYPE_5__ {int /*<<< orphan*/  source; int /*<<< orphan*/  slice; scalar_t__ vortex; } ;
typedef  TYPE_2__ a3dsrc_t ;

/* Variables and functions */
 int /*<<< orphan*/  A3D_A_CoeffTrackTC ; 
 int /*<<< orphan*/  A3D_A_GainTrackTC ; 
 int /*<<< orphan*/  A3D_A_HrtfTrackTC ; 
 int /*<<< orphan*/  A3D_A_ITDTrackTC ; 
 int /*<<< orphan*/  a3d_addrA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hwwrite (int /*<<< orphan*/ ,int /*<<< orphan*/ ,short) ; 

__attribute__((used)) static void
a3dsrc_SetTimeConsts(a3dsrc_t * a, short HrtfTrack, short ItdTrack,
		     short GTrack, short CTrack)
{
	vortex_t *vortex = (vortex_t *) (a->vortex);
	hwwrite(vortex->mmio,
		a3d_addrA(a->slice, a->source, A3D_A_HrtfTrackTC), HrtfTrack);
	hwwrite(vortex->mmio,
		a3d_addrA(a->slice, a->source, A3D_A_ITDTrackTC), ItdTrack);
	hwwrite(vortex->mmio,
		a3d_addrA(a->slice, a->source, A3D_A_GainTrackTC), GTrack);
	hwwrite(vortex->mmio,
		a3d_addrA(a->slice, a->source, A3D_A_CoeffTrackTC), CTrack);
}