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
struct spear_pwm_chip {scalar_t__ mmio_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  writel_relaxed (unsigned long,scalar_t__) ; 

__attribute__((used)) static inline void spear_pwm_writel(struct spear_pwm_chip *chip,
				    unsigned int num, unsigned long offset,
				    unsigned long val)
{
	writel_relaxed(val, chip->mmio_base + (num << 4) + offset);
}