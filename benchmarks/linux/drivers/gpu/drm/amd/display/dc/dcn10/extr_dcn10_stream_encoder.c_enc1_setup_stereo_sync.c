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
struct dcn10_stream_encoder {int dummy; } ;

/* Variables and functions */
 struct dcn10_stream_encoder* DCN10STRENC_FROM_STRENC (struct stream_encoder*) ; 
 int /*<<< orphan*/  DIG_FE_CNTL ; 
 int /*<<< orphan*/  DIG_STEREOSYNC_GATE_EN ; 
 int /*<<< orphan*/  DIG_STEREOSYNC_SELECT ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

void enc1_setup_stereo_sync(
	struct stream_encoder *enc,
	int tg_inst, bool enable)
{
	struct dcn10_stream_encoder *enc1 = DCN10STRENC_FROM_STRENC(enc);
	REG_UPDATE(DIG_FE_CNTL, DIG_STEREOSYNC_SELECT, tg_inst);
	REG_UPDATE(DIG_FE_CNTL, DIG_STEREOSYNC_GATE_EN, !enable);
}