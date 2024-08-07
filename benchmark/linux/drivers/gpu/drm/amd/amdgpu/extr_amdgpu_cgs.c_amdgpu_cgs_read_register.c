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
typedef  int /*<<< orphan*/  uint32_t ;
struct cgs_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CGS_FUNC_ADEV ; 
 int /*<<< orphan*/  RREG32 (unsigned int) ; 

__attribute__((used)) static uint32_t amdgpu_cgs_read_register(struct cgs_device *cgs_device, unsigned offset)
{
	CGS_FUNC_ADEV;
	return RREG32(offset);
}