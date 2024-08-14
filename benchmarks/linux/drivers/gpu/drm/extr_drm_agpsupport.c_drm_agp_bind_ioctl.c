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
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;
struct drm_agp_binding {int dummy; } ;

/* Variables and functions */
 int drm_agp_bind (struct drm_device*,struct drm_agp_binding*) ; 

int drm_agp_bind_ioctl(struct drm_device *dev, void *data,
		       struct drm_file *file_priv)
{
	struct drm_agp_binding *request = data;

	return drm_agp_bind(dev, request);
}