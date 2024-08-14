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
struct omap_overlay_manager_info {int partial_alpha_enabled; } ;
struct omap_overlay_manager {int /*<<< orphan*/  (* get_manager_info ) (struct omap_overlay_manager*,struct omap_overlay_manager_info*) ;} ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 int /*<<< orphan*/  FEAT_ALPHA_FIXED_ZORDER ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  dss_has_feature (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  stub1 (struct omap_overlay_manager*,struct omap_overlay_manager_info*) ; 

__attribute__((used)) static ssize_t manager_alpha_blending_enabled_show(
		struct omap_overlay_manager *mgr, char *buf)
{
	struct omap_overlay_manager_info info;

	if(!dss_has_feature(FEAT_ALPHA_FIXED_ZORDER))
		return -ENODEV;

	mgr->get_manager_info(mgr, &info);

	return snprintf(buf, PAGE_SIZE, "%d\n",
		info.partial_alpha_enabled);
}