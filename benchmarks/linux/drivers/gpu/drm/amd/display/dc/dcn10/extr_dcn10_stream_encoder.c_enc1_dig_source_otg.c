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
typedef  unsigned int uint32_t ;
struct stream_encoder {int dummy; } ;
struct dcn10_stream_encoder {int dummy; } ;

/* Variables and functions */
 struct dcn10_stream_encoder* DCN10STRENC_FROM_STRENC (struct stream_encoder*) ; 
 int /*<<< orphan*/  DIG_FE_CNTL ; 
 int /*<<< orphan*/  DIG_SOURCE_SELECT ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 

unsigned int enc1_dig_source_otg(
	struct stream_encoder *enc)
{
	uint32_t tg_inst = 0;
	struct dcn10_stream_encoder *enc1 = DCN10STRENC_FROM_STRENC(enc);

	REG_GET(DIG_FE_CNTL, DIG_SOURCE_SELECT, &tg_inst);

	return tg_inst;
}