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
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  REGULATOR_EVENT_REGULATION_OUT ; 
 int /*<<< orphan*/  REGULATOR_EVENT_UNDER_VOLTAGE ; 
 int WM8350_IRQ_CS1 ; 
 int WM8350_IRQ_CS2 ; 
 int /*<<< orphan*/  regulator_lock (struct regulator_dev*) ; 
 int /*<<< orphan*/  regulator_notifier_call_chain (struct regulator_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  regulator_unlock (struct regulator_dev*) ; 

__attribute__((used)) static irqreturn_t pmic_uv_handler(int irq, void *data)
{
	struct regulator_dev *rdev = (struct regulator_dev *)data;

	regulator_lock(rdev);
	if (irq == WM8350_IRQ_CS1 || irq == WM8350_IRQ_CS2)
		regulator_notifier_call_chain(rdev,
					      REGULATOR_EVENT_REGULATION_OUT,
					      NULL);
	else
		regulator_notifier_call_chain(rdev,
					      REGULATOR_EVENT_UNDER_VOLTAGE,
					      NULL);
	regulator_unlock(rdev);

	return IRQ_HANDLED;
}