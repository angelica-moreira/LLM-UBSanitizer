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
struct device {int dummy; } ;

/* Variables and functions */
 int amdgpu_device_suspend (struct drm_device*,int,int) ; 
 struct drm_device* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static int amdgpu_pmops_suspend(struct device *dev)
{
	struct drm_device *drm_dev = dev_get_drvdata(dev);

	return amdgpu_device_suspend(drm_dev, true, true);
}