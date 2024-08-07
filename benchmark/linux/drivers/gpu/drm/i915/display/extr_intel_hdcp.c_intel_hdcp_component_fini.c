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
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;
struct drm_i915_private {int hdcp_comp_added; TYPE_1__ drm; int /*<<< orphan*/  hdcp_comp_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  component_del (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i915_hdcp_component_ops ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void intel_hdcp_component_fini(struct drm_i915_private *dev_priv)
{
	mutex_lock(&dev_priv->hdcp_comp_mutex);
	if (!dev_priv->hdcp_comp_added) {
		mutex_unlock(&dev_priv->hdcp_comp_mutex);
		return;
	}

	dev_priv->hdcp_comp_added = false;
	mutex_unlock(&dev_priv->hdcp_comp_mutex);

	component_del(dev_priv->drm.dev, &i915_hdcp_component_ops);
}