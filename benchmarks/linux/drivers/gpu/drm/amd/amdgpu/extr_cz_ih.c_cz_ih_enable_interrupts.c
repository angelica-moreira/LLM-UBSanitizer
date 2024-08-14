#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_3__ {int enabled; } ;
struct TYPE_4__ {TYPE_1__ ih; } ;
struct amdgpu_device {TYPE_2__ irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENABLE_INTR ; 
 int /*<<< orphan*/  IH_CNTL ; 
 int /*<<< orphan*/  IH_RB_CNTL ; 
 int /*<<< orphan*/  RB_ENABLE ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmIH_CNTL ; 
 int /*<<< orphan*/  mmIH_RB_CNTL ; 

__attribute__((used)) static void cz_ih_enable_interrupts(struct amdgpu_device *adev)
{
	u32 ih_cntl = RREG32(mmIH_CNTL);
	u32 ih_rb_cntl = RREG32(mmIH_RB_CNTL);

	ih_cntl = REG_SET_FIELD(ih_cntl, IH_CNTL, ENABLE_INTR, 1);
	ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_ENABLE, 1);
	WREG32(mmIH_CNTL, ih_cntl);
	WREG32(mmIH_RB_CNTL, ih_rb_cntl);
	adev->irq.ih.enabled = true;
}