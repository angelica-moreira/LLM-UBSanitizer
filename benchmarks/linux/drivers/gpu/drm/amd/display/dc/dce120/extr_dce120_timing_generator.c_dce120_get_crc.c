#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct timing_generator {int /*<<< orphan*/  ctx; } ;
struct TYPE_2__ {int /*<<< orphan*/  crtc; } ;
struct dce110_timing_generator {TYPE_1__ offsets; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRC0_B_CB ; 
 int /*<<< orphan*/  CRC0_G_Y ; 
 int /*<<< orphan*/  CRC0_R_CR ; 
 int /*<<< orphan*/  CRTC0_CRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  CRTC0_CRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  CRTC0_CRTC_CRC_CNTL ; 
 int /*<<< orphan*/  CRTC_CRC_EN ; 
 struct dce110_timing_generator* DCE110TG_FROM_TG (struct timing_generator*) ; 
 int /*<<< orphan*/  dm_read_reg_soc15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_reg_field_value (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmCRTC0_CRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  mmCRTC0_CRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  mmCRTC0_CRTC_CRC_CNTL ; 

__attribute__((used)) static bool dce120_get_crc(struct timing_generator *tg, uint32_t *r_cr,
			   uint32_t *g_y, uint32_t *b_cb)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t value, field;

	value = dm_read_reg_soc15(tg->ctx, mmCRTC0_CRTC_CRC_CNTL,
				  tg110->offsets.crtc);
	field = get_reg_field_value(value, CRTC0_CRTC_CRC_CNTL, CRTC_CRC_EN);

	/* Early return if CRC is not enabled for this CRTC */
	if (!field)
		return false;

	value = dm_read_reg_soc15(tg->ctx, mmCRTC0_CRTC_CRC0_DATA_RG,
				  tg110->offsets.crtc);
	*r_cr = get_reg_field_value(value, CRTC0_CRTC_CRC0_DATA_RG, CRC0_R_CR);
	*g_y = get_reg_field_value(value, CRTC0_CRTC_CRC0_DATA_RG, CRC0_G_Y);

	value = dm_read_reg_soc15(tg->ctx, mmCRTC0_CRTC_CRC0_DATA_B,
				  tg110->offsets.crtc);
	*b_cb = get_reg_field_value(value, CRTC0_CRTC_CRC0_DATA_B, CRC0_B_CB);

	return true;
}