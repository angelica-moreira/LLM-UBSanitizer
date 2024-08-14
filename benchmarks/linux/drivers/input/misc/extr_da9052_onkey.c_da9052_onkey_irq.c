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
struct da9052_onkey {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  da9052_onkey_query (struct da9052_onkey*) ; 

__attribute__((used)) static irqreturn_t da9052_onkey_irq(int irq, void *data)
{
	struct da9052_onkey *onkey = data;

	da9052_onkey_query(onkey);

	return IRQ_HANDLED;
}