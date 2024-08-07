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
struct drm_psb_private {int /*<<< orphan*/  has_gct; } ;
struct drm_device {struct drm_psb_private* dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  gma_intel_teardown_gmbus (struct drm_device*) ; 
 int /*<<< orphan*/  oaktrail_hdmi_teardown (struct drm_device*) ; 
 int /*<<< orphan*/  psb_intel_destroy_bios (struct drm_device*) ; 

__attribute__((used)) static void oaktrail_teardown(struct drm_device *dev)
{
	struct drm_psb_private *dev_priv = dev->dev_private;

	gma_intel_teardown_gmbus(dev);
	oaktrail_hdmi_teardown(dev);
	if (!dev_priv->has_gct)
		psb_intel_destroy_bios(dev);
}