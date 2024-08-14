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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct phy_shim_info {int /*<<< orphan*/  wlc_hw; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcms_b_rate_shm_offset (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

u16 wlapi_bmac_rate_shm_offset(struct phy_shim_info *physhim, u8 rate)
{
	return brcms_b_rate_shm_offset(physhim->wlc_hw, rate);
}