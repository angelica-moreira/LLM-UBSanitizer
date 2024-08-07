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
typedef  scalar_t__ uint32_t ;
struct timing_generator {int /*<<< orphan*/  ctx; } ;
struct dce110_timing_generator {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRC0_B_CB ; 
 int /*<<< orphan*/  CRC0_G_Y ; 
 int /*<<< orphan*/  CRC0_R_CR ; 
 int /*<<< orphan*/  CRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  CRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  CRTC_CRC_CNTL ; 
 int /*<<< orphan*/  CRTC_CRC_EN ; 
 scalar_t__ CRTC_REG (int /*<<< orphan*/ ) ; 
 struct dce110_timing_generator* DCE110TG_FROM_TG (struct timing_generator*) ; 
 scalar_t__ dm_read_reg (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ get_reg_field_value (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmCRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  mmCRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  mmCRTC_CRC_CNTL ; 

bool dce110_get_crc(struct timing_generator *tg,
		    uint32_t *r_cr, uint32_t *g_y, uint32_t *b_cb)
{
	uint32_t addr = 0;
	uint32_t value = 0;
	uint32_t field = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	addr = CRTC_REG(mmCRTC_CRC_CNTL);
	value = dm_read_reg(tg->ctx, addr);
	field = get_reg_field_value(value, CRTC_CRC_CNTL, CRTC_CRC_EN);

	/* Early return if CRC is not enabled for this CRTC */
	if (!field)
		return false;

	addr = CRTC_REG(mmCRTC_CRC0_DATA_RG);
	value = dm_read_reg(tg->ctx, addr);
	*r_cr = get_reg_field_value(value, CRTC_CRC0_DATA_RG, CRC0_R_CR);
	*g_y = get_reg_field_value(value, CRTC_CRC0_DATA_RG, CRC0_G_Y);

	addr = CRTC_REG(mmCRTC_CRC0_DATA_B);
	value = dm_read_reg(tg->ctx, addr);
	*b_cb = get_reg_field_value(value, CRTC_CRC0_DATA_B, CRC0_B_CB);

	return true;
}