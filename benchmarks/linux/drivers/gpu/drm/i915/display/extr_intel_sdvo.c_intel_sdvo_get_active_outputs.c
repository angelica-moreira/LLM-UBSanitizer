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
typedef  int /*<<< orphan*/  u16 ;
struct intel_sdvo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SDVO_CMD_GET_ACTIVE_OUTPUTS ; 
 int intel_sdvo_get_value (struct intel_sdvo*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static bool intel_sdvo_get_active_outputs(struct intel_sdvo *intel_sdvo,
					  u16 *outputs)
{
	return intel_sdvo_get_value(intel_sdvo,
				    SDVO_CMD_GET_ACTIVE_OUTPUTS,
				    outputs, sizeof(*outputs));
}