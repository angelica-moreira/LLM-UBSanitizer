#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_40__   TYPE_9__ ;
typedef  struct TYPE_39__   TYPE_8__ ;
typedef  struct TYPE_38__   TYPE_7__ ;
typedef  struct TYPE_37__   TYPE_6__ ;
typedef  struct TYPE_36__   TYPE_5__ ;
typedef  struct TYPE_35__   TYPE_4__ ;
typedef  struct TYPE_34__   TYPE_3__ ;
typedef  struct TYPE_33__   TYPE_2__ ;
typedef  struct TYPE_32__   TYPE_20__ ;
typedef  struct TYPE_31__   TYPE_1__ ;
typedef  struct TYPE_30__   TYPE_19__ ;
typedef  struct TYPE_29__   TYPE_18__ ;
typedef  struct TYPE_28__   TYPE_17__ ;
typedef  struct TYPE_27__   TYPE_16__ ;
typedef  struct TYPE_26__   TYPE_15__ ;
typedef  struct TYPE_25__   TYPE_14__ ;
typedef  struct TYPE_24__   TYPE_13__ ;
typedef  struct TYPE_23__   TYPE_12__ ;
typedef  struct TYPE_22__   TYPE_11__ ;
typedef  struct TYPE_21__   TYPE_10__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct amdgpu_device {size_t*** reg_offset; } ;
struct TYPE_40__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_39__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_38__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_37__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_36__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_35__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_34__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_33__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_32__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_31__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_30__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_29__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_28__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_27__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_26__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_25__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_24__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_23__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_22__ {int /*<<< orphan*/ * instance; } ;
struct TYPE_21__ {int /*<<< orphan*/ * instance; } ;

/* Variables and functions */
 TYPE_20__ ATHUB_BASE ; 
 size_t ATHUB_HWIP ; 
 TYPE_19__ DF_BASE ; 
 size_t DF_HWIP ; 
 TYPE_18__ GC_BASE ; 
 size_t GC_HWIP ; 
 TYPE_17__ HDP_BASE ; 
 size_t HDP_HWIP ; 
 size_t MAX_INSTANCE ; 
 TYPE_16__ MMHUB_BASE ; 
 size_t MMHUB_HWIP ; 
 TYPE_15__ MP0_BASE ; 
 size_t MP0_HWIP ; 
 TYPE_14__ MP1_BASE ; 
 size_t MP1_HWIP ; 
 TYPE_13__ NBIF0_BASE ; 
 size_t NBIO_HWIP ; 
 TYPE_12__ OSSSYS_BASE ; 
 size_t OSSSYS_HWIP ; 
 TYPE_11__ SDMA0_BASE ; 
 size_t SDMA0_HWIP ; 
 TYPE_10__ SDMA1_BASE ; 
 size_t SDMA1_HWIP ; 
 TYPE_9__ SDMA2_BASE ; 
 size_t SDMA2_HWIP ; 
 TYPE_8__ SDMA3_BASE ; 
 size_t SDMA3_HWIP ; 
 TYPE_7__ SDMA4_BASE ; 
 size_t SDMA4_HWIP ; 
 TYPE_6__ SDMA5_BASE ; 
 size_t SDMA5_HWIP ; 
 TYPE_5__ SDMA6_BASE ; 
 size_t SDMA6_HWIP ; 
 TYPE_4__ SDMA7_BASE ; 
 size_t SDMA7_HWIP ; 
 TYPE_3__ SMUIO_BASE ; 
 size_t SMUIO_HWIP ; 
 TYPE_2__ THM_BASE ; 
 size_t THM_HWIP ; 
 TYPE_1__ UVD_BASE ; 
 size_t UVD_HWIP ; 

int arct_reg_base_init(struct amdgpu_device *adev)
{
	/* HW has more IP blocks,  only initialized the block needed by our driver  */
	uint32_t i;
	for (i = 0 ; i < MAX_INSTANCE ; ++i) {
		adev->reg_offset[GC_HWIP][i] = (uint32_t *)(&(GC_BASE.instance[i]));
		adev->reg_offset[HDP_HWIP][i] = (uint32_t *)(&(HDP_BASE.instance[i]));
		adev->reg_offset[MMHUB_HWIP][i] = (uint32_t *)(&(MMHUB_BASE.instance[i]));
		adev->reg_offset[ATHUB_HWIP][i] = (uint32_t *)(&(ATHUB_BASE.instance[i]));
		adev->reg_offset[NBIO_HWIP][i] = (uint32_t *)(&(NBIF0_BASE.instance[i]));
		adev->reg_offset[MP0_HWIP][i] = (uint32_t *)(&(MP0_BASE.instance[i]));
		adev->reg_offset[MP1_HWIP][i] = (uint32_t *)(&(MP1_BASE.instance[i]));
		adev->reg_offset[UVD_HWIP][i] = (uint32_t *)(&(UVD_BASE.instance[i]));
		adev->reg_offset[DF_HWIP][i] = (uint32_t *)(&(DF_BASE.instance[i]));
		adev->reg_offset[OSSSYS_HWIP][i] = (uint32_t *)(&(OSSSYS_BASE.instance[i]));
		adev->reg_offset[SDMA0_HWIP][i] = (uint32_t *)(&(SDMA0_BASE.instance[i]));
		adev->reg_offset[SDMA1_HWIP][i] = (uint32_t *)(&(SDMA1_BASE.instance[i]));
		adev->reg_offset[SDMA2_HWIP][i] = (uint32_t *)(&(SDMA2_BASE.instance[i]));
		adev->reg_offset[SDMA3_HWIP][i] = (uint32_t *)(&(SDMA3_BASE.instance[i]));
		adev->reg_offset[SDMA4_HWIP][i] = (uint32_t *)(&(SDMA4_BASE.instance[i]));
		adev->reg_offset[SDMA5_HWIP][i] = (uint32_t *)(&(SDMA5_BASE.instance[i]));
		adev->reg_offset[SDMA6_HWIP][i] = (uint32_t *)(&(SDMA6_BASE.instance[i]));
		adev->reg_offset[SDMA7_HWIP][i] = (uint32_t *)(&(SDMA7_BASE.instance[i]));
		adev->reg_offset[SMUIO_HWIP][i] = (uint32_t *)(&(SMUIO_BASE.instance[i]));
		adev->reg_offset[THM_HWIP][i] = (uint32_t *)(&(THM_BASE.instance[i]));
	}
	return 0;
}