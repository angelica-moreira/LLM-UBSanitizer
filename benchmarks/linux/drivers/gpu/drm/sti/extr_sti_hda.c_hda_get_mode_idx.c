#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct drm_display_mode {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  mode; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (TYPE_1__*) ; 
 scalar_t__ drm_mode_equal (int /*<<< orphan*/ *,struct drm_display_mode*) ; 
 TYPE_1__* hda_supported_modes ; 

__attribute__((used)) static bool hda_get_mode_idx(struct drm_display_mode mode, int *idx)
{
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(hda_supported_modes); i++)
		if (drm_mode_equal(&hda_supported_modes[i].mode, &mode)) {
			*idx = i;
			return true;
		}
	return false;
}