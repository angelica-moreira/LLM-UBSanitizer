#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct skl_plane_wm {int /*<<< orphan*/  trans_wm; int /*<<< orphan*/ * wm; } ;
struct skl_ddb_entry {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  dev; } ;
struct intel_plane {int id; int pipe; TYPE_1__ base; } ;
struct TYPE_6__ {struct skl_plane_wm* planes; } ;
struct TYPE_7__ {struct skl_ddb_entry* plane_ddb_y; TYPE_2__ optimal; } ;
struct TYPE_8__ {TYPE_3__ skl; } ;
struct intel_crtc_state {TYPE_4__ wm; } ;
struct drm_i915_private {int dummy; } ;
typedef  enum plane_id { ____Placeholder_plane_id } plane_id ;
typedef  enum pipe { ____Placeholder_pipe } pipe ;

/* Variables and functions */
 int /*<<< orphan*/  CUR_BUF_CFG (int) ; 
 int /*<<< orphan*/  CUR_WM (int,int) ; 
 int /*<<< orphan*/  CUR_WM_TRANS (int) ; 
 int ilk_wm_max_level (struct drm_i915_private*) ; 
 int /*<<< orphan*/  skl_ddb_entry_write (struct drm_i915_private*,int /*<<< orphan*/ ,struct skl_ddb_entry const*) ; 
 int /*<<< orphan*/  skl_write_wm_level (struct drm_i915_private*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct drm_i915_private* to_i915 (int /*<<< orphan*/ ) ; 

void skl_write_cursor_wm(struct intel_plane *plane,
			 const struct intel_crtc_state *crtc_state)
{
	struct drm_i915_private *dev_priv = to_i915(plane->base.dev);
	int level, max_level = ilk_wm_max_level(dev_priv);
	enum plane_id plane_id = plane->id;
	enum pipe pipe = plane->pipe;
	const struct skl_plane_wm *wm =
		&crtc_state->wm.skl.optimal.planes[plane_id];
	const struct skl_ddb_entry *ddb =
		&crtc_state->wm.skl.plane_ddb_y[plane_id];

	for (level = 0; level <= max_level; level++) {
		skl_write_wm_level(dev_priv, CUR_WM(pipe, level),
				   &wm->wm[level]);
	}
	skl_write_wm_level(dev_priv, CUR_WM_TRANS(pipe), &wm->trans_wm);

	skl_ddb_entry_write(dev_priv, CUR_BUF_CFG(pipe), ddb);
}