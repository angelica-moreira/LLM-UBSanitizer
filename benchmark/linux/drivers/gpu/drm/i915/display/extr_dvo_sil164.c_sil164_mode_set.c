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
struct intel_dvo_device {int dummy; } ;
struct drm_display_mode {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static void sil164_mode_set(struct intel_dvo_device *dvo,
			    const struct drm_display_mode *mode,
			    const struct drm_display_mode *adjusted_mode)
{
	/* As long as the basics are set up, since we don't have clock
	 * dependencies in the mode setup, we can just leave the
	 * registers alone and everything will work fine.
	 */
	/* recommended programming sequence from doc */
	/*sil164_writeb(sil, 0x08, 0x30);
	  sil164_writeb(sil, 0x09, 0x00);
	  sil164_writeb(sil, 0x0a, 0x90);
	  sil164_writeb(sil, 0x0c, 0x89);
	  sil164_writeb(sil, 0x08, 0x31);*/
	/* don't do much */
	return;
}