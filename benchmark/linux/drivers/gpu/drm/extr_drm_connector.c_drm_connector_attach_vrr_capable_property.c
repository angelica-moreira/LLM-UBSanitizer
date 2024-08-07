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
struct drm_property {int dummy; } ;
struct drm_device {int dummy; } ;
struct drm_connector {int /*<<< orphan*/  base; struct drm_property* vrr_capable_property; struct drm_device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_MODE_PROP_IMMUTABLE ; 
 int ENOMEM ; 
 int /*<<< orphan*/  drm_object_attach_property (int /*<<< orphan*/ *,struct drm_property*,int /*<<< orphan*/ ) ; 
 struct drm_property* drm_property_create_bool (struct drm_device*,int /*<<< orphan*/ ,char*) ; 

int drm_connector_attach_vrr_capable_property(
	struct drm_connector *connector)
{
	struct drm_device *dev = connector->dev;
	struct drm_property *prop;

	if (!connector->vrr_capable_property) {
		prop = drm_property_create_bool(dev, DRM_MODE_PROP_IMMUTABLE,
			"vrr_capable");
		if (!prop)
			return -ENOMEM;

		connector->vrr_capable_property = prop;
		drm_object_attach_property(&connector->base, prop, 0);
	}

	return 0;
}