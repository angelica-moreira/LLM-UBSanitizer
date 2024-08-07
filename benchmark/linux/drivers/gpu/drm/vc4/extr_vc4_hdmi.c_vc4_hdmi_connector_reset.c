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
struct drm_connector {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drm_atomic_helper_connector_reset (struct drm_connector*) ; 
 int /*<<< orphan*/  drm_atomic_helper_connector_tv_reset (struct drm_connector*) ; 

__attribute__((used)) static void vc4_hdmi_connector_reset(struct drm_connector *connector)
{
	drm_atomic_helper_connector_reset(connector);
	drm_atomic_helper_connector_tv_reset(connector);
}