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
typedef  int u32 ;
struct amdgpu_ih_ring {int ptr_mask; int rptr; int /*<<< orphan*/ * wptr_cpu; } ;
struct TYPE_2__ {struct amdgpu_ih_ring ih2; struct amdgpu_ih_ring ih1; struct amdgpu_ih_ring ih; } ;
struct amdgpu_device {TYPE_1__ irq; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  IH_RB_CNTL ; 
 int /*<<< orphan*/  IH_RB_WPTR ; 
 int /*<<< orphan*/  OSSSYS ; 
 int /*<<< orphan*/  RB_OVERFLOW ; 
 int /*<<< orphan*/  REG_GET_FIELD (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int REG_SET_FIELD (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int RREG32_NO_KIQ (int) ; 
 int SOC15_REG_OFFSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WPTR_OVERFLOW_CLEAR ; 
 int /*<<< orphan*/  WREG32_NO_KIQ (int,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmIH_RB_CNTL ; 
 int /*<<< orphan*/  mmIH_RB_CNTL_RING1 ; 
 int /*<<< orphan*/  mmIH_RB_CNTL_RING2 ; 
 int /*<<< orphan*/  mmIH_RB_WPTR ; 
 int /*<<< orphan*/  mmIH_RB_WPTR_RING1 ; 
 int /*<<< orphan*/  mmIH_RB_WPTR_RING2 ; 

__attribute__((used)) static u32 vega10_ih_get_wptr(struct amdgpu_device *adev,
			      struct amdgpu_ih_ring *ih)
{
	u32 wptr, reg, tmp;

	wptr = le32_to_cpu(*ih->wptr_cpu);

	if (!REG_GET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW))
		goto out;

	/* Double check that the overflow wasn't already cleared. */

	if (ih == &adev->irq.ih)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR);
	else if (ih == &adev->irq.ih1)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR_RING1);
	else if (ih == &adev->irq.ih2)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR_RING2);
	else
		BUG();

	wptr = RREG32_NO_KIQ(reg);
	if (!REG_GET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW))
		goto out;

	wptr = REG_SET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW, 0);

	/* When a ring buffer overflow happen start parsing interrupt
	 * from the last not overwritten vector (wptr + 32). Hopefully
	 * this should allow us to catchup.
	 */
	tmp = (wptr + 32) & ih->ptr_mask;
	dev_warn(adev->dev, "IH ring buffer overflow "
		 "(0x%08X, 0x%08X, 0x%08X)\n",
		 wptr, ih->rptr, tmp);
	ih->rptr = tmp;

	if (ih == &adev->irq.ih)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL);
	else if (ih == &adev->irq.ih1)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL_RING1);
	else if (ih == &adev->irq.ih2)
		reg = SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL_RING2);
	else
		BUG();

	tmp = RREG32_NO_KIQ(reg);
	tmp = REG_SET_FIELD(tmp, IH_RB_CNTL, WPTR_OVERFLOW_CLEAR, 1);
	WREG32_NO_KIQ(reg, tmp);

out:
	return (wptr & ih->ptr_mask);
}