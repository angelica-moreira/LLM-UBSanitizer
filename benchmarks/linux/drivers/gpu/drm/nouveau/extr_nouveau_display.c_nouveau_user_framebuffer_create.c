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
struct drm_framebuffer {int dummy; } ;
struct nouveau_framebuffer {struct drm_framebuffer base; } ;
struct nouveau_bo {int dummy; } ;
struct drm_mode_fb_cmd2 {int /*<<< orphan*/ * handles; } ;
struct drm_gem_object {int dummy; } ;
struct drm_file {int dummy; } ;
struct drm_device {int dummy; } ;

/* Variables and functions */
 int ENOENT ; 
 struct drm_framebuffer* ERR_PTR (int) ; 
 struct drm_gem_object* drm_gem_object_lookup (struct drm_file*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  drm_gem_object_put_unlocked (struct drm_gem_object*) ; 
 int nouveau_framebuffer_new (struct drm_device*,struct drm_mode_fb_cmd2 const*,struct nouveau_bo*,struct nouveau_framebuffer**) ; 
 struct nouveau_bo* nouveau_gem_object (struct drm_gem_object*) ; 

struct drm_framebuffer *
nouveau_user_framebuffer_create(struct drm_device *dev,
				struct drm_file *file_priv,
				const struct drm_mode_fb_cmd2 *mode_cmd)
{
	struct nouveau_framebuffer *fb;
	struct nouveau_bo *nvbo;
	struct drm_gem_object *gem;
	int ret;

	gem = drm_gem_object_lookup(file_priv, mode_cmd->handles[0]);
	if (!gem)
		return ERR_PTR(-ENOENT);
	nvbo = nouveau_gem_object(gem);

	ret = nouveau_framebuffer_new(dev, mode_cmd, nvbo, &fb);
	if (ret == 0)
		return &fb->base;

	drm_gem_object_put_unlocked(gem);
	return ERR_PTR(ret);
}