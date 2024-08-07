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
struct em_i2c_device {int /*<<< orphan*/  msg_done; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 scalar_t__ em_i2c_slave_irq (struct em_i2c_device*) ; 

__attribute__((used)) static irqreturn_t em_i2c_irq_handler(int this_irq, void *dev_id)
{
	struct em_i2c_device *priv = dev_id;

	if (em_i2c_slave_irq(priv))
		return IRQ_HANDLED;

	complete(&priv->msg_done);

	return IRQ_HANDLED;
}