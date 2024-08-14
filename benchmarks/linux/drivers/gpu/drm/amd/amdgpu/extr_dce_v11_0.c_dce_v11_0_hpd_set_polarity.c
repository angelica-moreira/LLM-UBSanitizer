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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int num_hpd; } ;
struct amdgpu_device {TYPE_1__ mode_info; } ;
typedef  enum amdgpu_hpd_id { ____Placeholder_amdgpu_hpd_id } amdgpu_hpd_id ;

/* Variables and functions */
 int /*<<< orphan*/  DC_HPD_INT_CONTROL ; 
 int /*<<< orphan*/  DC_HPD_INT_POLARITY ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RREG32 (scalar_t__) ; 
 int /*<<< orphan*/  WREG32 (scalar_t__,int /*<<< orphan*/ ) ; 
 int dce_v11_0_hpd_sense (struct amdgpu_device*,int) ; 
 scalar_t__* hpd_offsets ; 
 scalar_t__ mmDC_HPD_INT_CONTROL ; 

__attribute__((used)) static void dce_v11_0_hpd_set_polarity(struct amdgpu_device *adev,
				      enum amdgpu_hpd_id hpd)
{
	u32 tmp;
	bool connected = dce_v11_0_hpd_sense(adev, hpd);

	if (hpd >= adev->mode_info.num_hpd)
		return;

	tmp = RREG32(mmDC_HPD_INT_CONTROL + hpd_offsets[hpd]);
	if (connected)
		tmp = REG_SET_FIELD(tmp, DC_HPD_INT_CONTROL, DC_HPD_INT_POLARITY, 0);
	else
		tmp = REG_SET_FIELD(tmp, DC_HPD_INT_CONTROL, DC_HPD_INT_POLARITY, 1);
	WREG32(mmDC_HPD_INT_CONTROL + hpd_offsets[hpd], tmp);
}