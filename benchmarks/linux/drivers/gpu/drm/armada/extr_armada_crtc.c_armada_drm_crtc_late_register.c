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
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG_DEBUG_FS ; 
 scalar_t__ IS_ENABLED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  armada_drm_crtc_debugfs_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_to_armada_crtc (struct drm_crtc*) ; 

__attribute__((used)) static int armada_drm_crtc_late_register(struct drm_crtc *crtc)
{
	if (IS_ENABLED(CONFIG_DEBUG_FS))
		armada_drm_crtc_debugfs_init(drm_to_armada_crtc(crtc));

	return 0;
}