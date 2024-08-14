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
struct vmw_private {int /*<<< orphan*/  enable_fb; } ;
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  vmw_kms_legacy_hotspot_clear (struct vmw_private*) ; 
 struct vmw_private* vmw_priv (struct drm_device*) ; 
 int /*<<< orphan*/  vmw_svga_disable (struct vmw_private*) ; 

__attribute__((used)) static void vmw_master_drop(struct drm_device *dev,
			    struct drm_file *file_priv)
{
	struct vmw_private *dev_priv = vmw_priv(dev);

	vmw_kms_legacy_hotspot_clear(dev_priv);
	if (!dev_priv->enable_fb)
		vmw_svga_disable(dev_priv);
}