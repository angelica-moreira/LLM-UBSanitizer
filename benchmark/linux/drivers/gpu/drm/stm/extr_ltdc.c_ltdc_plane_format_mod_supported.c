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
typedef  scalar_t__ u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct drm_plane {int dummy; } ;

/* Variables and functions */
 scalar_t__ DRM_FORMAT_MOD_LINEAR ; 

__attribute__((used)) static bool ltdc_plane_format_mod_supported(struct drm_plane *plane,
					    u32 format,
					    u64 modifier)
{
	if (modifier == DRM_FORMAT_MOD_LINEAR)
		return true;

	return false;
}