#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct ptn3460_bridge {int /*<<< orphan*/  panel; } ;
struct drm_bridge {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*) ; 
 struct ptn3460_bridge* bridge_to_ptn3460 (struct drm_bridge*) ; 
 scalar_t__ drm_panel_unprepare (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ptn3460_post_disable(struct drm_bridge *bridge)
{
	struct ptn3460_bridge *ptn_bridge = bridge_to_ptn3460(bridge);

	if (drm_panel_unprepare(ptn_bridge->panel)) {
		DRM_ERROR("failed to unprepare panel\n");
		return;
	}
}