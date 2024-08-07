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
typedef  enum swizzle_mode_values { ____Placeholder_swizzle_mode_values } swizzle_mode_values ;
typedef  enum source_macro_tile_size { ____Placeholder_source_macro_tile_size } source_macro_tile_size ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
#define  DC_SW_256B_S 149 
#define  DC_SW_4KB_D 148 
#define  DC_SW_4KB_D_X 147 
#define  DC_SW_4KB_R 146 
#define  DC_SW_4KB_R_X 145 
#define  DC_SW_4KB_S 144 
#define  DC_SW_4KB_S_X 143 
#define  DC_SW_64KB_D 142 
#define  DC_SW_64KB_D_T 141 
#define  DC_SW_64KB_D_X 140 
#define  DC_SW_64KB_R 139 
#define  DC_SW_64KB_R_X 138 
#define  DC_SW_64KB_S 137 
#define  DC_SW_64KB_S_T 136 
#define  DC_SW_64KB_S_X 135 
#define  DC_SW_LINEAR 134 
#define  DC_SW_VAR_D 133 
#define  DC_SW_VAR_D_X 132 
#define  DC_SW_VAR_R 131 
#define  DC_SW_VAR_R_X 130 
#define  DC_SW_VAR_S 129 
#define  DC_SW_VAR_S_X 128 
 int dm_256k_tile ; 
 int dm_4k_tile ; 
 int dm_64k_tile ; 

enum source_macro_tile_size swizzle_mode_to_macro_tile_size(enum swizzle_mode_values sw_mode)
{
	switch (sw_mode) {
	/* for 4/8/16 high tiles */
	case DC_SW_LINEAR:
		return dm_4k_tile;
	case DC_SW_4KB_S:
	case DC_SW_4KB_S_X:
		return dm_4k_tile;
	case DC_SW_64KB_S:
	case DC_SW_64KB_S_X:
	case DC_SW_64KB_S_T:
		return dm_64k_tile;
	case DC_SW_VAR_S:
	case DC_SW_VAR_S_X:
		return dm_256k_tile;

	/* For 64bpp 2 high tiles */
	case DC_SW_4KB_D:
	case DC_SW_4KB_D_X:
		return dm_4k_tile;
	case DC_SW_64KB_D:
	case DC_SW_64KB_D_X:
	case DC_SW_64KB_D_T:
		return dm_64k_tile;
	case DC_SW_VAR_D:
	case DC_SW_VAR_D_X:
		return dm_256k_tile;

	case DC_SW_4KB_R:
	case DC_SW_4KB_R_X:
		return dm_4k_tile;
	case DC_SW_64KB_R:
	case DC_SW_64KB_R_X:
		return dm_64k_tile;
	case DC_SW_VAR_R:
	case DC_SW_VAR_R_X:
		return dm_256k_tile;

	/* Unsupported swizzle modes for dcn */
	case DC_SW_256B_S:
	default:
		ASSERT(0); /* Not supported */
		return 0;
	}
}