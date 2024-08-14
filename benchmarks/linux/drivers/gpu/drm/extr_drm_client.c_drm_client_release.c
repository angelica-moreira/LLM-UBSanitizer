#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct drm_device {int /*<<< orphan*/  dev; } ;
struct drm_client_dev {TYPE_1__* funcs; int /*<<< orphan*/  name; struct drm_device* dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  owner; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEV_DEBUG_KMS (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_client_close (struct drm_client_dev*) ; 
 int /*<<< orphan*/  drm_client_modeset_free (struct drm_client_dev*) ; 
 int /*<<< orphan*/  drm_dev_put (struct drm_device*) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 

void drm_client_release(struct drm_client_dev *client)
{
	struct drm_device *dev = client->dev;

	DRM_DEV_DEBUG_KMS(dev->dev, "%s\n", client->name);

	drm_client_modeset_free(client);
	drm_client_close(client);
	drm_dev_put(dev);
	if (client->funcs)
		module_put(client->funcs->owner);
}