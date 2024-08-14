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
struct TYPE_2__ {int /*<<< orphan*/  atpx; } ;

/* Variables and functions */
 TYPE_1__ amdgpu_atpx_priv ; 
 int amdgpu_atpx_validate (int /*<<< orphan*/ *) ; 
 int amdgpu_atpx_verify_interface (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int amdgpu_atpx_init(void)
{
	int r;

	/* set up the ATPX handle */
	r = amdgpu_atpx_verify_interface(&amdgpu_atpx_priv.atpx);
	if (r)
		return r;

	/* validate the atpx setup */
	r = amdgpu_atpx_validate(&amdgpu_atpx_priv.atpx);
	if (r)
		return r;

	return 0;
}