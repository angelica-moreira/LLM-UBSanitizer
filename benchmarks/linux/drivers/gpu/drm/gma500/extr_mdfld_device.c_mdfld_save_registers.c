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
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mdfld_disable_crtc (struct drm_device*,int) ; 
 int /*<<< orphan*/  mdfld_save_display_registers (struct drm_device*,int) ; 

__attribute__((used)) static int mdfld_save_registers(struct drm_device *dev)
{
	/* mdfld_save_cursor_overlay_registers(dev); */
	mdfld_save_display_registers(dev, 0);
	mdfld_save_display_registers(dev, 2);
	mdfld_disable_crtc(dev, 0);
	mdfld_disable_crtc(dev, 2);

	return 0;
}