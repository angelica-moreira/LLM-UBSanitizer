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
struct drm_gem_object {int dummy; } ;
struct drm_gem_cma_object {int dummy; } ;
struct drm_framebuffer {int dummy; } ;

/* Variables and functions */
 struct drm_gem_object* drm_gem_fb_get_obj (struct drm_framebuffer*,unsigned int) ; 
 struct drm_gem_cma_object* to_drm_gem_cma_obj (struct drm_gem_object*) ; 

struct drm_gem_cma_object *drm_fb_cma_get_gem_obj(struct drm_framebuffer *fb,
						  unsigned int plane)
{
	struct drm_gem_object *gem;

	gem = drm_gem_fb_get_obj(fb, plane);
	if (!gem)
		return NULL;

	return to_drm_gem_cma_obj(gem);
}