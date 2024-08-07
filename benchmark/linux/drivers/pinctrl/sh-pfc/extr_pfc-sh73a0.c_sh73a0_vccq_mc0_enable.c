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
struct regulator_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sh73a0_vccq_mc0_endisable (struct regulator_dev*,int) ; 

__attribute__((used)) static int sh73a0_vccq_mc0_enable(struct regulator_dev *reg)
{
	sh73a0_vccq_mc0_endisable(reg, true);
	return 0;
}