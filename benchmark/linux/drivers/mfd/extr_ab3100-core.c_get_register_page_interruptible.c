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
typedef  int /*<<< orphan*/  u8 ;
struct device {int /*<<< orphan*/  parent; } ;
struct ab3100 {int dummy; } ;

/* Variables and functions */
 int ab3100_get_register_page_interruptible (struct ab3100*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct ab3100* dev_get_drvdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_register_page_interruptible(struct device *dev, u8 bank,
	u8 first_reg, u8 *regvals, u8 numregs)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return ab3100_get_register_page_interruptible(ab3100,
			first_reg, regvals, numregs);
}