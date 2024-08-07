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

/* Variables and functions */
 int drm_mode_addfb (struct drm_device*,void*,struct drm_file*) ; 

int drm_mode_addfb_ioctl(struct drm_device *dev,
			 void *data, struct drm_file *file_priv)
{
	return drm_mode_addfb(dev, data, file_priv);
}