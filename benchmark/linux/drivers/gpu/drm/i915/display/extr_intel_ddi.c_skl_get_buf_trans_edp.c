#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ low_vswing; } ;
struct TYPE_4__ {TYPE_1__ edp; } ;
struct drm_i915_private {TYPE_2__ vbt; } ;
struct ddi_buf_trans {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct ddi_buf_trans const*) ; 
 scalar_t__ IS_CFL_ULT (struct drm_i915_private*) ; 
 scalar_t__ IS_CFL_ULX (struct drm_i915_private*) ; 
 scalar_t__ IS_COFFEELAKE (struct drm_i915_private*) ; 
 scalar_t__ IS_KABYLAKE (struct drm_i915_private*) ; 
 scalar_t__ IS_KBL_ULT (struct drm_i915_private*) ; 
 scalar_t__ IS_KBL_ULX (struct drm_i915_private*) ; 
 scalar_t__ IS_SKL_ULT (struct drm_i915_private*) ; 
 scalar_t__ IS_SKL_ULX (struct drm_i915_private*) ; 
 struct ddi_buf_trans const* kbl_get_buf_trans_dp (struct drm_i915_private*,int*) ; 
 struct ddi_buf_trans const* skl_ddi_translations_edp ; 
 struct ddi_buf_trans const* skl_get_buf_trans_dp (struct drm_i915_private*,int*) ; 
 struct ddi_buf_trans const* skl_u_ddi_translations_edp ; 
 struct ddi_buf_trans const* skl_y_ddi_translations_edp ; 

__attribute__((used)) static const struct ddi_buf_trans *
skl_get_buf_trans_edp(struct drm_i915_private *dev_priv, int *n_entries)
{
	if (dev_priv->vbt.edp.low_vswing) {
		if (IS_SKL_ULX(dev_priv) || IS_KBL_ULX(dev_priv) ||
		    IS_CFL_ULX(dev_priv)) {
			*n_entries = ARRAY_SIZE(skl_y_ddi_translations_edp);
			return skl_y_ddi_translations_edp;
		} else if (IS_SKL_ULT(dev_priv) || IS_KBL_ULT(dev_priv) ||
			   IS_CFL_ULT(dev_priv)) {
			*n_entries = ARRAY_SIZE(skl_u_ddi_translations_edp);
			return skl_u_ddi_translations_edp;
		} else {
			*n_entries = ARRAY_SIZE(skl_ddi_translations_edp);
			return skl_ddi_translations_edp;
		}
	}

	if (IS_KABYLAKE(dev_priv) || IS_COFFEELAKE(dev_priv))
		return kbl_get_buf_trans_dp(dev_priv, n_entries);
	else
		return skl_get_buf_trans_dp(dev_priv, n_entries);
}