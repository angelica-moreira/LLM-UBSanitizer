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
struct mv88e6xxx_chip {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  mv88e6xxx_g1_irq_thread_work (struct mv88e6xxx_chip*) ; 

__attribute__((used)) static irqreturn_t mv88e6xxx_g1_irq_thread_fn(int irq, void *dev_id)
{
	struct mv88e6xxx_chip *chip = dev_id;

	return mv88e6xxx_g1_irq_thread_work(chip);
}