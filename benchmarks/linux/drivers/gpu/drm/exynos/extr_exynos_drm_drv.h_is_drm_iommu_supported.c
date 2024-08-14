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
struct exynos_drm_private {scalar_t__ mapping; } ;
struct drm_device {struct exynos_drm_private* dev_private; } ;

/* Variables and functions */

__attribute__((used)) static inline bool is_drm_iommu_supported(struct drm_device *drm_dev)
{
	struct exynos_drm_private *priv = drm_dev->dev_private;

	return priv->mapping ? true : false;
}