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
struct intel_sdvo {int dummy; } ;

/* Variables and functions */
 int intel_sdvo_check_supp_encode (struct intel_sdvo*) ; 

__attribute__((used)) static bool
intel_sdvo_is_hdmi_connector(struct intel_sdvo *intel_sdvo, int device)
{
	return intel_sdvo_check_supp_encode(intel_sdvo);
}