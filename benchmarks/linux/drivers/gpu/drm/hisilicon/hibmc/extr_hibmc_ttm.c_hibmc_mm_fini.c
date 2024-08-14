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
struct hibmc_drm_private {TYPE_1__* dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  vram_mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_vram_helper_release_mm (TYPE_1__*) ; 

void hibmc_mm_fini(struct hibmc_drm_private *hibmc)
{
	if (!hibmc->dev->vram_mm)
		return;

	drm_vram_helper_release_mm(hibmc->dev);
}