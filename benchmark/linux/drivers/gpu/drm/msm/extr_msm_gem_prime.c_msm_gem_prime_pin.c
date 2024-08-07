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
struct drm_gem_object {int /*<<< orphan*/  import_attach; } ;

/* Variables and functions */
 int /*<<< orphan*/  msm_gem_get_pages (struct drm_gem_object*) ; 

int msm_gem_prime_pin(struct drm_gem_object *obj)
{
	if (!obj->import_attach)
		msm_gem_get_pages(obj);
	return 0;
}