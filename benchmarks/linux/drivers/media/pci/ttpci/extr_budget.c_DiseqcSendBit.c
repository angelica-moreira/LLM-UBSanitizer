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
struct saa7146_dev {int dummy; } ;
struct budget {struct saa7146_dev* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  SAA7146_GPIO_OUTHI ; 
 int /*<<< orphan*/  SAA7146_GPIO_OUTLO ; 
 int /*<<< orphan*/  dprintk (int,char*,struct budget*) ; 
 int /*<<< orphan*/  saa7146_setgpio (struct saa7146_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void DiseqcSendBit (struct budget *budget, int data)
{
	struct saa7146_dev *dev=budget->dev;
	dprintk(2, "budget: %p\n", budget);

	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
	udelay(data ? 500 : 1000);
	saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
	udelay(data ? 1000 : 500);
}