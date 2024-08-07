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
struct etnaviv_gpu {int dummy; } ;
struct etnaviv_drm_private {struct etnaviv_gpu** gpu; } ;
struct drm_file {int dummy; } ;
struct drm_etnaviv_pm_domain {size_t pipe; } ;
struct drm_device {struct etnaviv_drm_private* dev_private; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENXIO ; 
 size_t ETNA_MAX_PIPES ; 
 int etnaviv_pm_query_dom (struct etnaviv_gpu*,struct drm_etnaviv_pm_domain*) ; 

__attribute__((used)) static int etnaviv_ioctl_pm_query_dom(struct drm_device *dev, void *data,
	struct drm_file *file)
{
	struct etnaviv_drm_private *priv = dev->dev_private;
	struct drm_etnaviv_pm_domain *args = data;
	struct etnaviv_gpu *gpu;

	if (args->pipe >= ETNA_MAX_PIPES)
		return -EINVAL;

	gpu = priv->gpu[args->pipe];
	if (!gpu)
		return -ENXIO;

	return etnaviv_pm_query_dom(gpu, args);
}