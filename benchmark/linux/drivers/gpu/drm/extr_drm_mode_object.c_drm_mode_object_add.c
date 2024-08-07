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
typedef  int /*<<< orphan*/  uint32_t ;
struct drm_mode_object {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int __drm_mode_object_add (struct drm_device*,struct drm_mode_object*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

int drm_mode_object_add(struct drm_device *dev,
			struct drm_mode_object *obj, uint32_t obj_type)
{
	return __drm_mode_object_add(dev, obj, obj_type, true, NULL);
}