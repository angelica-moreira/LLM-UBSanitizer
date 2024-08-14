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
struct drm_plane {TYPE_1__* dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_plane_cleanup (struct drm_plane*) ; 
 int /*<<< orphan*/  vmw_cursor_update_position (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void vmw_du_cursor_plane_destroy(struct drm_plane *plane)
{
	vmw_cursor_update_position(plane->dev->dev_private, false, 0, 0);

	drm_plane_cleanup(plane);
}