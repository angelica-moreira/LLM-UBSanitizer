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
typedef  int uint32_t ;
struct msm_gpu {int dummy; } ;

/* Variables and functions */
 int ETIMEDOUT ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int gpu_read (struct msm_gpu*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int spin_usecs(struct msm_gpu *gpu, uint32_t usecs,
		uint32_t reg, uint32_t mask, uint32_t value)
{
	while (usecs--) {
		udelay(1);
		if ((gpu_read(gpu, reg) & mask) == value)
			return 0;
		cpu_relax();
	}

	return -ETIMEDOUT;
}