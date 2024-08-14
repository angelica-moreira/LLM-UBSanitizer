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
struct gpio_pin_info {int /*<<< orphan*/  mask; int /*<<< orphan*/  mask_mask; int /*<<< orphan*/  mask_en; int /*<<< orphan*/  mask_y; void* offset; void* offset_mask; void* offset_en; void* offset_y; } ;
typedef  enum gpio_id { ____Placeholder_gpio_id } gpio_id ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
 int /*<<< orphan*/  DC_GPIO_DDC6_A__DC_GPIO_DDC6CLK_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_DDC6_A__DC_GPIO_DDC6DATA_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICA_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICB_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICC_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICD_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICE_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICF_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENERIC_A__DC_GPIO_GENERICG_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENLK_A__DC_GPIO_GENLK_CLK_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENLK_A__DC_GPIO_GENLK_VSYNC_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_A_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_B_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD1_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD2_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD3_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD4_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD5_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_HPD_A__DC_GPIO_HPD6_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_SYNCA_A__DC_GPIO_HSYNCA_A_MASK ; 
 int /*<<< orphan*/  DC_GPIO_SYNCA_A__DC_GPIO_VSYNCA_A_MASK ; 
#define  GPIO_DDC_LINE_DDC1 163 
#define  GPIO_DDC_LINE_DDC2 162 
#define  GPIO_DDC_LINE_DDC3 161 
#define  GPIO_DDC_LINE_DDC4 160 
#define  GPIO_DDC_LINE_DDC5 159 
#define  GPIO_DDC_LINE_DDC6 158 
#define  GPIO_DDC_LINE_DDC_VGA 157 
#define  GPIO_DDC_LINE_I2C_PAD 156 
#define  GPIO_GENERIC_A 155 
#define  GPIO_GENERIC_B 154 
#define  GPIO_GENERIC_C 153 
#define  GPIO_GENERIC_D 152 
#define  GPIO_GENERIC_E 151 
#define  GPIO_GENERIC_F 150 
#define  GPIO_GENERIC_G 149 
#define  GPIO_GSL_GENLOCK_CLOCK 148 
#define  GPIO_GSL_GENLOCK_VSYNC 147 
#define  GPIO_GSL_SWAPLOCK_A 146 
#define  GPIO_GSL_SWAPLOCK_B 145 
#define  GPIO_HPD_1 144 
#define  GPIO_HPD_2 143 
#define  GPIO_HPD_3 142 
#define  GPIO_HPD_4 141 
#define  GPIO_HPD_5 140 
#define  GPIO_HPD_6 139 
#define  GPIO_ID_DDC_CLOCK 138 
#define  GPIO_ID_DDC_DATA 137 
#define  GPIO_ID_GENERIC 136 
#define  GPIO_ID_GSL 135 
#define  GPIO_ID_HPD 134 
#define  GPIO_ID_SYNC 133 
#define  GPIO_ID_VIP_PAD 132 
#define  GPIO_SYNC_HSYNC_A 131 
#define  GPIO_SYNC_HSYNC_B 130 
#define  GPIO_SYNC_VSYNC_A 129 
#define  GPIO_SYNC_VSYNC_B 128 
 void* mmDC_GPIO_DDC1_A ; 
 void* mmDC_GPIO_DDC2_A ; 
 void* mmDC_GPIO_DDC3_A ; 
 void* mmDC_GPIO_DDC4_A ; 
 void* mmDC_GPIO_DDC5_A ; 
 void* mmDC_GPIO_DDC6_A ; 
 void* mmDC_GPIO_DDCVGA_A ; 
 void* mmDC_GPIO_GENERIC_A ; 
 void* mmDC_GPIO_GENLK_A ; 
 void* mmDC_GPIO_HPD_A ; 
 void* mmDC_GPIO_I2CPAD_A ; 
 void* mmDC_GPIO_SYNCA_A ; 

__attribute__((used)) static bool id_to_offset(
	enum gpio_id id,
	uint32_t en,
	struct gpio_pin_info *info)
{
	bool result = true;

	switch (id) {
	case GPIO_ID_DDC_DATA:
		info->mask = DC_GPIO_DDC6_A__DC_GPIO_DDC6DATA_A_MASK;
		switch (en) {
		case GPIO_DDC_LINE_DDC1:
			info->offset = mmDC_GPIO_DDC1_A;
		break;
		case GPIO_DDC_LINE_DDC2:
			info->offset = mmDC_GPIO_DDC2_A;
		break;
		case GPIO_DDC_LINE_DDC3:
			info->offset = mmDC_GPIO_DDC3_A;
		break;
		case GPIO_DDC_LINE_DDC4:
			info->offset = mmDC_GPIO_DDC4_A;
		break;
		case GPIO_DDC_LINE_DDC5:
			info->offset = mmDC_GPIO_DDC5_A;
		break;
		case GPIO_DDC_LINE_DDC6:
			info->offset = mmDC_GPIO_DDC6_A;
		break;
		case GPIO_DDC_LINE_DDC_VGA:
			info->offset = mmDC_GPIO_DDCVGA_A;
		break;
		case GPIO_DDC_LINE_I2C_PAD:
			info->offset = mmDC_GPIO_I2CPAD_A;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_DDC_CLOCK:
		info->mask = DC_GPIO_DDC6_A__DC_GPIO_DDC6CLK_A_MASK;
		switch (en) {
		case GPIO_DDC_LINE_DDC1:
			info->offset = mmDC_GPIO_DDC1_A;
		break;
		case GPIO_DDC_LINE_DDC2:
			info->offset = mmDC_GPIO_DDC2_A;
		break;
		case GPIO_DDC_LINE_DDC3:
			info->offset = mmDC_GPIO_DDC3_A;
		break;
		case GPIO_DDC_LINE_DDC4:
			info->offset = mmDC_GPIO_DDC4_A;
		break;
		case GPIO_DDC_LINE_DDC5:
			info->offset = mmDC_GPIO_DDC5_A;
		break;
		case GPIO_DDC_LINE_DDC6:
			info->offset = mmDC_GPIO_DDC6_A;
		break;
		case GPIO_DDC_LINE_DDC_VGA:
			info->offset = mmDC_GPIO_DDCVGA_A;
		break;
		case GPIO_DDC_LINE_I2C_PAD:
			info->offset = mmDC_GPIO_I2CPAD_A;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_GENERIC:
		info->offset = mmDC_GPIO_GENERIC_A;
		switch (en) {
		case GPIO_GENERIC_A:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICA_A_MASK;
		break;
		case GPIO_GENERIC_B:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICB_A_MASK;
		break;
		case GPIO_GENERIC_C:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICC_A_MASK;
		break;
		case GPIO_GENERIC_D:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICD_A_MASK;
		break;
		case GPIO_GENERIC_E:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICE_A_MASK;
		break;
		case GPIO_GENERIC_F:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICF_A_MASK;
		break;
		case GPIO_GENERIC_G:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICG_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_HPD:
		info->offset = mmDC_GPIO_HPD_A;
		switch (en) {
		case GPIO_HPD_1:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD1_A_MASK;
		break;
		case GPIO_HPD_2:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD2_A_MASK;
		break;
		case GPIO_HPD_3:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD3_A_MASK;
		break;
		case GPIO_HPD_4:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD4_A_MASK;
		break;
		case GPIO_HPD_5:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD5_A_MASK;
		break;
		case GPIO_HPD_6:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD6_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_SYNC:
		switch (en) {
		case GPIO_SYNC_HSYNC_A:
			info->offset = mmDC_GPIO_SYNCA_A;
			info->mask = DC_GPIO_SYNCA_A__DC_GPIO_HSYNCA_A_MASK;
		break;
		case GPIO_SYNC_VSYNC_A:
			info->offset = mmDC_GPIO_SYNCA_A;
			info->mask = DC_GPIO_SYNCA_A__DC_GPIO_VSYNCA_A_MASK;
		break;
		case GPIO_SYNC_HSYNC_B:
		case GPIO_SYNC_VSYNC_B:
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_GSL:
		switch (en) {
		case GPIO_GSL_GENLOCK_CLOCK:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_GENLK_CLK_A_MASK;
		break;
		case GPIO_GSL_GENLOCK_VSYNC:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask =
				DC_GPIO_GENLK_A__DC_GPIO_GENLK_VSYNC_A_MASK;
		break;
		case GPIO_GSL_SWAPLOCK_A:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_A_A_MASK;
		break;
		case GPIO_GSL_SWAPLOCK_B:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_B_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_VIP_PAD:
	default:
		ASSERT_CRITICAL(false);
		result = false;
	}

	if (result) {
		info->offset_y = info->offset + 2;
		info->offset_en = info->offset + 1;
		info->offset_mask = info->offset - 1;

		info->mask_y = info->mask;
		info->mask_en = info->mask;
		info->mask_mask = info->mask;
	}

	return result;
}