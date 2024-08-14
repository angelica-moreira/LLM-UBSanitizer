#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct dpg_pause_state {scalar_t__ fw_based; scalar_t__ jpeg; } ;
struct amdgpu_ring {int gpu_addr; int ring_size; int wptr; } ;
struct TYPE_4__ {scalar_t__ fw_based; scalar_t__ jpeg; } ;
struct TYPE_6__ {TYPE_1__ pause_state; TYPE_2__* inst; } ;
struct amdgpu_device {TYPE_3__ vcn; } ;
struct TYPE_5__ {struct amdgpu_ring ring_dec; struct amdgpu_ring ring_jpeg; struct amdgpu_ring* ring_enc; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_DEBUG (char*,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOC15_WAIT_ON_RREG (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  UVD ; 
 int UVD_DPG_PAUSE__JPEG_PAUSE_DPG_ACK_MASK ; 
 int UVD_DPG_PAUSE__JPEG_PAUSE_DPG_REQ_MASK ; 
 int UVD_DPG_PAUSE__NJ_PAUSE_DPG_ACK_MASK ; 
 int UVD_DPG_PAUSE__NJ_PAUSE_DPG_REQ_MASK ; 
 int UVD_JRBC_RB_CNTL__RB_NO_FETCH_MASK ; 
 int UVD_JRBC_RB_CNTL__RB_RPTR_WR_EN_MASK ; 
 int UVD_PGFSM_CONFIG__UVDM_UVDU_PWR_ON ; 
 int UVD_POWER_STATUS__JRBC_SNOOP_DIS_MASK ; 
 int UVD_POWER_STATUS__UVD_POWER_STATUS_MASK ; 
 int UVD_POWER_STATUS__UVD_POWER_STATUS_TILES_OFF ; 
 scalar_t__ VCN_DPG_STATE__PAUSE ; 
 int /*<<< orphan*/  WREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int lower_32_bits (int) ; 
 int /*<<< orphan*/  mmUVD_DPG_PAUSE ; 
 int /*<<< orphan*/  mmUVD_JRBC_RB_CNTL ; 
 int /*<<< orphan*/  mmUVD_JRBC_RB_RPTR ; 
 int /*<<< orphan*/  mmUVD_JRBC_RB_WPTR ; 
 int /*<<< orphan*/  mmUVD_LMI_JRBC_RB_64BIT_BAR_HIGH ; 
 int /*<<< orphan*/  mmUVD_LMI_JRBC_RB_64BIT_BAR_LOW ; 
 int /*<<< orphan*/  mmUVD_LMI_JRBC_RB_VMID ; 
 int /*<<< orphan*/  mmUVD_POWER_STATUS ; 
 int /*<<< orphan*/  mmUVD_RBC_RB_WPTR ; 
 int /*<<< orphan*/  mmUVD_RB_BASE_HI ; 
 int /*<<< orphan*/  mmUVD_RB_BASE_HI2 ; 
 int /*<<< orphan*/  mmUVD_RB_BASE_LO ; 
 int /*<<< orphan*/  mmUVD_RB_BASE_LO2 ; 
 int /*<<< orphan*/  mmUVD_RB_RPTR ; 
 int /*<<< orphan*/  mmUVD_RB_RPTR2 ; 
 int /*<<< orphan*/  mmUVD_RB_SIZE ; 
 int /*<<< orphan*/  mmUVD_RB_SIZE2 ; 
 int /*<<< orphan*/  mmUVD_RB_WPTR ; 
 int /*<<< orphan*/  mmUVD_RB_WPTR2 ; 
 int /*<<< orphan*/  mmUVD_SCRATCH2 ; 
 int upper_32_bits (int) ; 

__attribute__((used)) static int vcn_v1_0_pause_dpg_mode(struct amdgpu_device *adev,
				struct dpg_pause_state *new_state)
{
	int ret_code;
	uint32_t reg_data = 0;
	uint32_t reg_data2 = 0;
	struct amdgpu_ring *ring;

	/* pause/unpause if state is changed */
	if (adev->vcn.pause_state.fw_based != new_state->fw_based) {
		DRM_DEBUG("dpg pause state changed %d:%d -> %d:%d",
			adev->vcn.pause_state.fw_based, adev->vcn.pause_state.jpeg,
			new_state->fw_based, new_state->jpeg);

		reg_data = RREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE) &
			(~UVD_DPG_PAUSE__NJ_PAUSE_DPG_ACK_MASK);

		if (new_state->fw_based == VCN_DPG_STATE__PAUSE) {
			ret_code = 0;

			if (!(reg_data & UVD_DPG_PAUSE__JPEG_PAUSE_DPG_ACK_MASK))
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_POWER_STATUS,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_TILES_OFF,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_MASK, ret_code);

			if (!ret_code) {
				/* pause DPG non-jpeg */
				reg_data |= UVD_DPG_PAUSE__NJ_PAUSE_DPG_REQ_MASK;
				WREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE, reg_data);
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_DPG_PAUSE,
						   UVD_DPG_PAUSE__NJ_PAUSE_DPG_ACK_MASK,
						   UVD_DPG_PAUSE__NJ_PAUSE_DPG_ACK_MASK, ret_code);

				/* Restore */
				ring = &adev->vcn.inst->ring_enc[0];
				WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_LO, ring->gpu_addr);
				WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_HI, upper_32_bits(ring->gpu_addr));
				WREG32_SOC15(UVD, 0, mmUVD_RB_SIZE, ring->ring_size / 4);
				WREG32_SOC15(UVD, 0, mmUVD_RB_RPTR, lower_32_bits(ring->wptr));
				WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR, lower_32_bits(ring->wptr));

				ring = &adev->vcn.inst->ring_enc[1];
				WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_LO2, ring->gpu_addr);
				WREG32_SOC15(UVD, 0, mmUVD_RB_BASE_HI2, upper_32_bits(ring->gpu_addr));
				WREG32_SOC15(UVD, 0, mmUVD_RB_SIZE2, ring->ring_size / 4);
				WREG32_SOC15(UVD, 0, mmUVD_RB_RPTR2, lower_32_bits(ring->wptr));
				WREG32_SOC15(UVD, 0, mmUVD_RB_WPTR2, lower_32_bits(ring->wptr));

				ring = &adev->vcn.inst->ring_dec;
				WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR,
						   RREG32_SOC15(UVD, 0, mmUVD_SCRATCH2) & 0x7FFFFFFF);
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_POWER_STATUS,
						   UVD_PGFSM_CONFIG__UVDM_UVDU_PWR_ON,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_MASK, ret_code);
			}
		} else {
			/* unpause dpg non-jpeg, no need to wait */
			reg_data &= ~UVD_DPG_PAUSE__NJ_PAUSE_DPG_REQ_MASK;
			WREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE, reg_data);
		}
		adev->vcn.pause_state.fw_based = new_state->fw_based;
	}

	/* pause/unpause if state is changed */
	if (adev->vcn.pause_state.jpeg != new_state->jpeg) {
		DRM_DEBUG("dpg pause state changed %d:%d -> %d:%d",
			adev->vcn.pause_state.fw_based, adev->vcn.pause_state.jpeg,
			new_state->fw_based, new_state->jpeg);

		reg_data = RREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE) &
			(~UVD_DPG_PAUSE__JPEG_PAUSE_DPG_ACK_MASK);

		if (new_state->jpeg == VCN_DPG_STATE__PAUSE) {
			ret_code = 0;

			if (!(reg_data & UVD_DPG_PAUSE__NJ_PAUSE_DPG_ACK_MASK))
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_POWER_STATUS,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_TILES_OFF,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_MASK, ret_code);

			if (!ret_code) {
				/* Make sure JPRG Snoop is disabled before sending the pause */
				reg_data2 = RREG32_SOC15(UVD, 0, mmUVD_POWER_STATUS);
				reg_data2 |= UVD_POWER_STATUS__JRBC_SNOOP_DIS_MASK;
				WREG32_SOC15(UVD, 0, mmUVD_POWER_STATUS, reg_data2);

				/* pause DPG jpeg */
				reg_data |= UVD_DPG_PAUSE__JPEG_PAUSE_DPG_REQ_MASK;
				WREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE, reg_data);
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_DPG_PAUSE,
							UVD_DPG_PAUSE__JPEG_PAUSE_DPG_ACK_MASK,
							UVD_DPG_PAUSE__JPEG_PAUSE_DPG_ACK_MASK, ret_code);

				/* Restore */
				ring = &adev->vcn.inst->ring_jpeg;
				WREG32_SOC15(UVD, 0, mmUVD_LMI_JRBC_RB_VMID, 0);
				WREG32_SOC15(UVD, 0, mmUVD_JRBC_RB_CNTL,
							UVD_JRBC_RB_CNTL__RB_NO_FETCH_MASK |
							UVD_JRBC_RB_CNTL__RB_RPTR_WR_EN_MASK);
				WREG32_SOC15(UVD, 0, mmUVD_LMI_JRBC_RB_64BIT_BAR_LOW,
							lower_32_bits(ring->gpu_addr));
				WREG32_SOC15(UVD, 0, mmUVD_LMI_JRBC_RB_64BIT_BAR_HIGH,
							upper_32_bits(ring->gpu_addr));
				WREG32_SOC15(UVD, 0, mmUVD_JRBC_RB_RPTR, ring->wptr);
				WREG32_SOC15(UVD, 0, mmUVD_JRBC_RB_WPTR, ring->wptr);
				WREG32_SOC15(UVD, 0, mmUVD_JRBC_RB_CNTL,
							UVD_JRBC_RB_CNTL__RB_RPTR_WR_EN_MASK);

				ring = &adev->vcn.inst->ring_dec;
				WREG32_SOC15(UVD, 0, mmUVD_RBC_RB_WPTR,
						   RREG32_SOC15(UVD, 0, mmUVD_SCRATCH2) & 0x7FFFFFFF);
				SOC15_WAIT_ON_RREG(UVD, 0, mmUVD_POWER_STATUS,
						   UVD_PGFSM_CONFIG__UVDM_UVDU_PWR_ON,
						   UVD_POWER_STATUS__UVD_POWER_STATUS_MASK, ret_code);
			}
		} else {
			/* unpause dpg jpeg, no need to wait */
			reg_data &= ~UVD_DPG_PAUSE__JPEG_PAUSE_DPG_REQ_MASK;
			WREG32_SOC15(UVD, 0, mmUVD_DPG_PAUSE, reg_data);
		}
		adev->vcn.pause_state.jpeg = new_state->jpeg;
	}

	return 0;
}