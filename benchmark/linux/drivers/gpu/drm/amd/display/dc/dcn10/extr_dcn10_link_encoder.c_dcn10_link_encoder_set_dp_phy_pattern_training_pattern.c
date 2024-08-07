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
typedef  int /*<<< orphan*/  uint32_t ;
struct link_encoder {int dummy; } ;
struct dcn10_link_encoder {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DP_DPHY_TRAINING_PATTERN_SEL ; 
 int /*<<< orphan*/  REG_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dcn10_link_encoder* TO_DCN10_LINK_ENC (struct link_encoder*) ; 
 int /*<<< orphan*/  disable_prbs_mode (struct dcn10_link_encoder*) ; 
 int /*<<< orphan*/  enable_phy_bypass_mode (struct dcn10_link_encoder*,int) ; 
 int /*<<< orphan*/  set_link_training_complete (struct dcn10_link_encoder*,int) ; 

void dcn10_link_encoder_set_dp_phy_pattern_training_pattern(
	struct link_encoder *enc,
	uint32_t index)
{
	struct dcn10_link_encoder *enc10 = TO_DCN10_LINK_ENC(enc);
	/* Write Training Pattern */

	REG_WRITE(DP_DPHY_TRAINING_PATTERN_SEL, index);

	/* Set HW Register Training Complete to false */

	set_link_training_complete(enc10, false);

	/* Disable PHY Bypass mode to output Training Pattern */

	enable_phy_bypass_mode(enc10, false);

	/* Disable PRBS mode */
	disable_prbs_mode(enc10);
}