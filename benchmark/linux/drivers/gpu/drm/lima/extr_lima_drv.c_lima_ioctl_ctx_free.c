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
struct lima_drm_priv {int /*<<< orphan*/  ctx_mgr; } ;
struct drm_lima_ctx_create {int /*<<< orphan*/  id; scalar_t__ _pad; } ;
struct drm_file {struct lima_drm_priv* driver_priv; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int lima_ctx_free (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lima_ioctl_ctx_free(struct drm_device *dev, void *data, struct drm_file *file)
{
	struct drm_lima_ctx_create *args = data;
	struct lima_drm_priv *priv = file->driver_priv;

	if (args->_pad)
		return -EINVAL;

	return lima_ctx_free(&priv->ctx_mgr, args->id);
}