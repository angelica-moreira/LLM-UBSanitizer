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
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sdma_v2_4_enable (struct amdgpu_device*,int) ; 
 int sdma_v2_4_gfx_resume (struct amdgpu_device*) ; 
 int sdma_v2_4_rlc_resume (struct amdgpu_device*) ; 

__attribute__((used)) static int sdma_v2_4_start(struct amdgpu_device *adev)
{
	int r;

	/* halt the engine before programing */
	sdma_v2_4_enable(adev, false);

	/* start the gfx rings and rlc compute queues */
	r = sdma_v2_4_gfx_resume(adev);
	if (r)
		return r;
	r = sdma_v2_4_rlc_resume(adev);
	if (r)
		return r;

	return 0;
}