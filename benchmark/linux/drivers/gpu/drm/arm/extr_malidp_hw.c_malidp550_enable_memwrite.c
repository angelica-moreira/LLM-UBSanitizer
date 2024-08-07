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
typedef  int const u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct malidp_hw_device {int /*<<< orphan*/  mw_state; } ;
typedef  int const s32 ;
typedef  int s16 ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int const MALIDP550_SE_CONTROL ; 
 int MALIDP550_SE_MEMWRITE_BASE ; 
 int MALIDP550_SE_MEMWRITE_ONESHOT ; 
 int const MALIDP550_SE_MEMWRITE_OUT_SIZE ; 
 int const MALIDP550_SE_RGB_YUV_COEFFS ; 
 int MALIDP_COLORADJ_NUM_COEFFS ; 
 int /*<<< orphan*/  MALIDP_DE_BLOCK ; 
 int const MALIDP_DE_DISPLAY_FUNC ; 
 int const MALIDP_DE_H_ACTIVE (int /*<<< orphan*/ ) ; 
 int const MALIDP_DE_V_ACTIVE (int /*<<< orphan*/ ) ; 
 int const MALIDP_MW_FORMAT ; 
 int const MALIDP_MW_P1_PTR_HIGH ; 
 int const MALIDP_MW_P1_PTR_LOW ; 
 int const MALIDP_MW_P1_STRIDE ; 
 int const MALIDP_MW_P2_PTR_HIGH ; 
 int const MALIDP_MW_P2_PTR_LOW ; 
 int const MALIDP_MW_P2_STRIDE ; 
 int MALIDP_SCALE_ENGINE_EN ; 
 int MALIDP_SE_MEMWRITE_EN ; 
 int /*<<< orphan*/  MW_ONESHOT ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 int const lower_32_bits (int /*<<< orphan*/ ) ; 
 int malidp_get_block_base (struct malidp_hw_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  malidp_hw_setbits (struct malidp_hw_device*,int,int const) ; 
 int /*<<< orphan*/  malidp_hw_write (struct malidp_hw_device*,int const,int const) ; 
 int const upper_32_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int malidp550_enable_memwrite(struct malidp_hw_device *hwdev,
				     dma_addr_t *addrs, s32 *pitches,
				     int num_planes, u16 w, u16 h, u32 fmt_id,
				     const s16 *rgb2yuv_coeffs)
{
	u32 base = MALIDP550_SE_MEMWRITE_BASE;
	u32 de_base = malidp_get_block_base(hwdev, MALIDP_DE_BLOCK);

	/* enable the scaling engine block */
	malidp_hw_setbits(hwdev, MALIDP_SCALE_ENGINE_EN, de_base + MALIDP_DE_DISPLAY_FUNC);

	hwdev->mw_state = MW_ONESHOT;

	malidp_hw_write(hwdev, fmt_id, base + MALIDP_MW_FORMAT);
	switch (num_planes) {
	case 2:
		malidp_hw_write(hwdev, lower_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[1]), base + MALIDP_MW_P2_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[1], base + MALIDP_MW_P2_STRIDE);
		/* fall through */
	case 1:
		malidp_hw_write(hwdev, lower_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_LOW);
		malidp_hw_write(hwdev, upper_32_bits(addrs[0]), base + MALIDP_MW_P1_PTR_HIGH);
		malidp_hw_write(hwdev, pitches[0], base + MALIDP_MW_P1_STRIDE);
		break;
	default:
		WARN(1, "Invalid number of planes");
	}

	malidp_hw_write(hwdev, MALIDP_DE_H_ACTIVE(w) | MALIDP_DE_V_ACTIVE(h),
			MALIDP550_SE_MEMWRITE_OUT_SIZE);
	malidp_hw_setbits(hwdev, MALIDP550_SE_MEMWRITE_ONESHOT | MALIDP_SE_MEMWRITE_EN,
			  MALIDP550_SE_CONTROL);

	if (rgb2yuv_coeffs) {
		int i;

		for (i = 0; i < MALIDP_COLORADJ_NUM_COEFFS; i++) {
			malidp_hw_write(hwdev, rgb2yuv_coeffs[i],
					MALIDP550_SE_RGB_YUV_COEFFS + i * 4);
		}
	}

	return 0;
}