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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ AVIVO_D1CRTC_STATUS ; 
 int AVIVO_D1CRTC_V_BLANK ; 
 int RREG32 (scalar_t__) ; 
 scalar_t__* crtc_offsets ; 

__attribute__((used)) static bool avivo_is_in_vblank(struct radeon_device *rdev, int crtc)
{
	if (RREG32(AVIVO_D1CRTC_STATUS + crtc_offsets[crtc]) & AVIVO_D1CRTC_V_BLANK)
		return true;
	else
		return false;
}