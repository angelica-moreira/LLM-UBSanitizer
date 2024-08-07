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
struct mdp5_plane_state {int dummy; } ;
struct drm_plane_state {scalar_t__ fb; } ;
struct drm_plane {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_framebuffer_put (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct mdp5_plane_state*) ; 
 struct mdp5_plane_state* to_mdp5_plane_state (struct drm_plane_state*) ; 

__attribute__((used)) static void mdp5_plane_destroy_state(struct drm_plane *plane,
		struct drm_plane_state *state)
{
	struct mdp5_plane_state *pstate = to_mdp5_plane_state(state);

	if (state->fb)
		drm_framebuffer_put(state->fb);

	kfree(pstate);
}