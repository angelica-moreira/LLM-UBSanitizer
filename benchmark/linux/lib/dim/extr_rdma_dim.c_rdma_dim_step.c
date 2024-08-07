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
struct dim {scalar_t__ tune_state; int profile_ix; int /*<<< orphan*/  steps_left; int /*<<< orphan*/  steps_right; } ;

/* Variables and functions */
 scalar_t__ DIM_GOING_LEFT ; 
 scalar_t__ DIM_GOING_RIGHT ; 
 int DIM_ON_EDGE ; 
 int DIM_STEPPED ; 
 int RDMA_DIM_PARAMS_NUM_PROFILES ; 

__attribute__((used)) static int rdma_dim_step(struct dim *dim)
{
	if (dim->tune_state == DIM_GOING_RIGHT) {
		if (dim->profile_ix == (RDMA_DIM_PARAMS_NUM_PROFILES - 1))
			return DIM_ON_EDGE;
		dim->profile_ix++;
		dim->steps_right++;
	}
	if (dim->tune_state == DIM_GOING_LEFT) {
		if (dim->profile_ix == 0)
			return DIM_ON_EDGE;
		dim->profile_ix--;
		dim->steps_left++;
	}

	return DIM_STEPPED;
}