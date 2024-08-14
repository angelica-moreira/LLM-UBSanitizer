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
struct dispc_device {int dummy; } ;
typedef  enum omap_plane_id { ____Placeholder_omap_plane_id } omap_plane_id ;
typedef  enum omap_overlay_caps { ____Placeholder_omap_overlay_caps } omap_overlay_caps ;

/* Variables and functions */
 int /*<<< orphan*/  DISPC_OVL_ATTRIBUTES (int) ; 
 int OMAP_DSS_OVL_CAP_REPLICATION ; 
 int /*<<< orphan*/  REG_FLD_MOD (struct dispc_device*,int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static void dispc_ovl_enable_replication(struct dispc_device *dispc,
					 enum omap_plane_id plane,
					 enum omap_overlay_caps caps,
					 bool enable)
{
	static const unsigned int shifts[] = { 5, 10, 10, 10 };
	int shift;

	if ((caps & OMAP_DSS_OVL_CAP_REPLICATION) == 0)
		return;

	shift = shifts[plane];
	REG_FLD_MOD(dispc, DISPC_OVL_ATTRIBUTES(plane), enable, shift, shift);
}