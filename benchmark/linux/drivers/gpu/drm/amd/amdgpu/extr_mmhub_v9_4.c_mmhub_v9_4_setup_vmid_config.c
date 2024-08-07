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
struct TYPE_2__ {int num_level; int block_size; scalar_t__ max_pfn; } ;
struct amdgpu_device {TYPE_1__ vm_manager; } ;

/* Variables and functions */
 int /*<<< orphan*/  DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  ENABLE_CONTEXT ; 
 int /*<<< orphan*/  EXECUTE_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  MMHUB ; 
 int MMHUB_INSTANCE_REGISTER_OFFSET ; 
 int /*<<< orphan*/  PAGE_TABLE_BLOCK_SIZE ; 
 int /*<<< orphan*/  PAGE_TABLE_DEPTH ; 
 int /*<<< orphan*/  PDE0_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  RANGE_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  READ_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RETRY_PERMISSION_OR_INVALID_PAGE_FAULT ; 
 int /*<<< orphan*/  RREG32_SOC15_OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  VALID_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  VML2VC0_VM_CONTEXT1_CNTL ; 
 int /*<<< orphan*/  WREG32_SOC15_OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_PROTECTION_FAULT_ENABLE_DEFAULT ; 
 int /*<<< orphan*/  lower_32_bits (scalar_t__) ; 
 int /*<<< orphan*/  mmVML2VC0_VM_CONTEXT1_CNTL ; 
 int /*<<< orphan*/  mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_END_ADDR_HI32 ; 
 int /*<<< orphan*/  mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_END_ADDR_LO32 ; 
 int /*<<< orphan*/  mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_START_ADDR_HI32 ; 
 int /*<<< orphan*/  mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_START_ADDR_LO32 ; 
 int /*<<< orphan*/  upper_32_bits (scalar_t__) ; 

__attribute__((used)) static void mmhub_v9_4_setup_vmid_config(struct amdgpu_device *adev, int hubid)
{
	uint32_t tmp;
	int i;

	for (i = 0; i <= 14; i++) {
		tmp = RREG32_SOC15_OFFSET(MMHUB, 0, mmVML2VC0_VM_CONTEXT1_CNTL,
				hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    ENABLE_CONTEXT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    PAGE_TABLE_DEPTH,
				    adev->vm_manager.num_level);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    RANGE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    DUMMY_PAGE_PROTECTION_FAULT_ENABLE_DEFAULT,
				    1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    PDE0_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    VALID_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    READ_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    WRITE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    EXECUTE_PROTECTION_FAULT_ENABLE_DEFAULT, 1);
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    PAGE_TABLE_BLOCK_SIZE,
				    adev->vm_manager.block_size - 9);
		/* Send no-retry XNACK on fault to suppress VM fault storm. */
		tmp = REG_SET_FIELD(tmp, VML2VC0_VM_CONTEXT1_CNTL,
				    RETRY_PERMISSION_OR_INVALID_PAGE_FAULT, 0);
		WREG32_SOC15_OFFSET(MMHUB, 0, mmVML2VC0_VM_CONTEXT1_CNTL,
				    hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i,
				    tmp);
		WREG32_SOC15_OFFSET(MMHUB, 0,
			    mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_START_ADDR_LO32,
			    hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i*2, 0);
		WREG32_SOC15_OFFSET(MMHUB, 0,
			    mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_START_ADDR_HI32,
			    hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i*2, 0);
		WREG32_SOC15_OFFSET(MMHUB, 0,
				mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_END_ADDR_LO32,
				hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i*2,
				lower_32_bits(adev->vm_manager.max_pfn - 1));
		WREG32_SOC15_OFFSET(MMHUB, 0,
				mmVML2VC0_VM_CONTEXT1_PAGE_TABLE_END_ADDR_HI32,
				hubid * MMHUB_INSTANCE_REGISTER_OFFSET + i*2,
				upper_32_bits(adev->vm_manager.max_pfn - 1));
	}
}