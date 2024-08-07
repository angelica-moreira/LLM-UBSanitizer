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
struct intel_crtc_state {int /*<<< orphan*/  base; } ;

/* Variables and functions */
 int drm_atomic_crtc_needs_modeset (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool
needs_modeset(const struct intel_crtc_state *state)
{
	return drm_atomic_crtc_needs_modeset(&state->base);
}