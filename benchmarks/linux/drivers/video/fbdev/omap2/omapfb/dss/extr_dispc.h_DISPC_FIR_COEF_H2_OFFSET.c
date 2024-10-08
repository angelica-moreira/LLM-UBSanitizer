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
typedef  int u16 ;
typedef  enum omap_plane { ____Placeholder_omap_plane } omap_plane ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
#define  OMAP_DSS_GFX 132 
#define  OMAP_DSS_VIDEO1 131 
#define  OMAP_DSS_VIDEO2 130 
#define  OMAP_DSS_VIDEO3 129 
#define  OMAP_DSS_WB 128 

__attribute__((used)) static inline u16 DISPC_FIR_COEF_H2_OFFSET(enum omap_plane plane, u16 i)
{
	switch (plane) {
	case OMAP_DSS_GFX:
		BUG();
		return 0;
	case OMAP_DSS_VIDEO1:
		return 0x058C + i * 0x8;
	case OMAP_DSS_VIDEO2:
		return 0x0568 + i * 0x8;
	case OMAP_DSS_VIDEO3:
		return 0x0430 + i * 0x8;
	case OMAP_DSS_WB:
		return 0x02A0 + i * 0x8;
	default:
		BUG();
		return 0;
	}
}