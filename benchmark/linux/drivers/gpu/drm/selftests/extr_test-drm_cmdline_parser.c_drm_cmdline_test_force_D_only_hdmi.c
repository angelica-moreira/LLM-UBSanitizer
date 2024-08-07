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
struct drm_cmdline_mode {int specified; int refresh_specified; int bpp_specified; int rb; int cvt; int interlace; int margins; scalar_t__ force; } ;

/* Variables and functions */
 scalar_t__ DRM_FORCE_ON_DIGITAL ; 
 int /*<<< orphan*/  FAIL_ON (int) ; 
 int /*<<< orphan*/  connector_hdmi ; 
 int /*<<< orphan*/  drm_mode_parse_command_line_for_connector (char*,int /*<<< orphan*/ *,struct drm_cmdline_mode*) ; 

__attribute__((used)) static int drm_cmdline_test_force_D_only_hdmi(void *ignored)
{
	struct drm_cmdline_mode mode = { };

	FAIL_ON(!drm_mode_parse_command_line_for_connector("D",
							   &connector_hdmi,
							   &mode));
	FAIL_ON(mode.specified);
	FAIL_ON(mode.refresh_specified);
	FAIL_ON(mode.bpp_specified);

	FAIL_ON(mode.rb);
	FAIL_ON(mode.cvt);
	FAIL_ON(mode.interlace);
	FAIL_ON(mode.margins);
	FAIL_ON(mode.force != DRM_FORCE_ON_DIGITAL);

	return 0;
}