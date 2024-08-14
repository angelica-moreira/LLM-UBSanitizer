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
struct sharp_nt_panel {int enabled; int /*<<< orphan*/  backlight; } ;
struct drm_panel {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  backlight_disable (int /*<<< orphan*/ ) ; 
 struct sharp_nt_panel* to_sharp_nt_panel (struct drm_panel*) ; 

__attribute__((used)) static int sharp_nt_panel_disable(struct drm_panel *panel)
{
	struct sharp_nt_panel *sharp_nt = to_sharp_nt_panel(panel);

	if (!sharp_nt->enabled)
		return 0;

	backlight_disable(sharp_nt->backlight);

	sharp_nt->enabled = false;

	return 0;
}