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
struct TYPE_3__ {unsigned int y; unsigned int adjusted_y; } ;
struct TYPE_4__ {TYPE_1__ plane; } ;
struct intel_fbc {TYPE_2__ state_cache; } ;

/* Variables and functions */

__attribute__((used)) static unsigned int get_crtc_fence_y_offset(struct intel_fbc *fbc)
{
	return fbc->state_cache.plane.y - fbc->state_cache.plane.adjusted_y;
}