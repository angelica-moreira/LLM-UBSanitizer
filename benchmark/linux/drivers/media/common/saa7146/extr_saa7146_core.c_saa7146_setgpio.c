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
typedef  int u32 ;
struct saa7146_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  GPIO_CTRL ; 
 int saa7146_read (struct saa7146_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  saa7146_write (struct saa7146_dev*,int /*<<< orphan*/ ,int) ; 

void saa7146_setgpio(struct saa7146_dev *dev, int port, u32 data)
{
	u32 value = 0;

	BUG_ON(port > 3);

	value = saa7146_read(dev, GPIO_CTRL);
	value &= ~(0xff << (8*port));
	value |= (data << (8*port));
	saa7146_write(dev, GPIO_CTRL, value);
}