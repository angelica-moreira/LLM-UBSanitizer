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
struct stream_encoder {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dce110_se_enable_audio_clock (struct stream_encoder*,int) ; 

void dce110_se_hdmi_audio_disable(
	struct stream_encoder *enc)
{
	dce110_se_enable_audio_clock(enc, false);
}