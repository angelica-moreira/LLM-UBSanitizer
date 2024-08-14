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
struct mdp4_kms {int /*<<< orphan*/  base; } ;
struct mdp4_crtc {int enabled; int /*<<< orphan*/  err; int /*<<< orphan*/  name; } ;
struct drm_crtc_state {int dummy; } ;
struct drm_crtc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  drm_crtc_vblank_off (struct drm_crtc*) ; 
 struct mdp4_kms* get_kms (struct drm_crtc*) ; 
 int /*<<< orphan*/  mdp4_disable (struct mdp4_kms*) ; 
 int /*<<< orphan*/  mdp_irq_unregister (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 struct mdp4_crtc* to_mdp4_crtc (struct drm_crtc*) ; 

__attribute__((used)) static void mdp4_crtc_atomic_disable(struct drm_crtc *crtc,
				     struct drm_crtc_state *old_state)
{
	struct mdp4_crtc *mdp4_crtc = to_mdp4_crtc(crtc);
	struct mdp4_kms *mdp4_kms = get_kms(crtc);

	DBG("%s", mdp4_crtc->name);

	if (WARN_ON(!mdp4_crtc->enabled))
		return;

	/* Disable/save vblank irq handling before power is disabled */
	drm_crtc_vblank_off(crtc);

	mdp_irq_unregister(&mdp4_kms->base, &mdp4_crtc->err);
	mdp4_disable(mdp4_kms);

	mdp4_crtc->enabled = false;
}