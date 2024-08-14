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
struct drm_plane_state {int dummy; } ;
struct drm_plane {int dummy; } ;
struct dm_plane_state {scalar_t__ dc_state; } ;

/* Variables and functions */
 int /*<<< orphan*/  dc_plane_state_release (scalar_t__) ; 
 int /*<<< orphan*/  drm_atomic_helper_plane_destroy_state (struct drm_plane*,struct drm_plane_state*) ; 
 struct dm_plane_state* to_dm_plane_state (struct drm_plane_state*) ; 

void dm_drm_plane_destroy_state(struct drm_plane *plane,
				struct drm_plane_state *state)
{
	struct dm_plane_state *dm_plane_state = to_dm_plane_state(state);

	if (dm_plane_state->dc_state)
		dc_plane_state_release(dm_plane_state->dc_state);

	drm_atomic_helper_plane_destroy_state(plane, state);
}