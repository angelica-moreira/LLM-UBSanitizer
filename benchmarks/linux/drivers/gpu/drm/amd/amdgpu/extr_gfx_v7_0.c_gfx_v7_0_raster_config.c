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
typedef  int u32 ;
struct amdgpu_device {int asic_type; } ;

/* Variables and functions */
#define  CHIP_BONAIRE 132 
#define  CHIP_HAWAII 131 
#define  CHIP_KABINI 130 
#define  CHIP_KAVERI 129 
#define  CHIP_MULLINS 128 
 int /*<<< orphan*/  DRM_ERROR (char*,int) ; 
 int PKR_MAP (int) ; 
 int PKR_XSEL (int) ; 
 int PKR_YSEL (int) ; 
 int RB_MAP_PKR0 (int) ; 
 int RB_MAP_PKR1 (int) ; 
 int RB_XSEL2 (int) ; 
 int SE_MAP (int) ; 
 int SE_PAIR_MAP (int) ; 
 int SE_PAIR_XSEL (int) ; 
 int SE_PAIR_YSEL (int) ; 
 int SE_XSEL (int) ; 
 int SE_YSEL (int) ; 

__attribute__((used)) static void
gfx_v7_0_raster_config(struct amdgpu_device *adev, u32 *rconf, u32 *rconf1)
{
	switch (adev->asic_type) {
	case CHIP_BONAIRE:
		*rconf |= RB_MAP_PKR0(2) | RB_XSEL2(1) | SE_MAP(2) |
			  SE_XSEL(1) | SE_YSEL(1);
		*rconf1 |= 0x0;
		break;
	case CHIP_HAWAII:
		*rconf |= RB_MAP_PKR0(2) | RB_MAP_PKR1(2) |
			  RB_XSEL2(1) | PKR_MAP(2) | PKR_XSEL(1) |
			  PKR_YSEL(1) | SE_MAP(2) | SE_XSEL(2) |
			  SE_YSEL(3);
		*rconf1 |= SE_PAIR_MAP(2) | SE_PAIR_XSEL(3) |
			   SE_PAIR_YSEL(2);
		break;
	case CHIP_KAVERI:
		*rconf |= RB_MAP_PKR0(2);
		*rconf1 |= 0x0;
		break;
	case CHIP_KABINI:
	case CHIP_MULLINS:
		*rconf |= 0x0;
		*rconf1 |= 0x0;
		break;
	default:
		DRM_ERROR("unknown asic: 0x%x\n", adev->asic_type);
		break;
	}
}