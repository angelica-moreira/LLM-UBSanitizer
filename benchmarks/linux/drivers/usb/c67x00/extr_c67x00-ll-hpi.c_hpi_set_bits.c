#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;
struct c67x00_device {TYPE_1__ hpi; } ;

/* Variables and functions */
 int hpi_read_word_nolock (struct c67x00_device*,int) ; 
 int /*<<< orphan*/  hpi_write_word_nolock (struct c67x00_device*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void hpi_set_bits(struct c67x00_device *dev, u16 reg, u16 mask)
{
	u16 value;
	unsigned long flags;

	spin_lock_irqsave(&dev->hpi.lock, flags);
	value = hpi_read_word_nolock(dev, reg);
	hpi_write_word_nolock(dev, reg, value | mask);
	spin_unlock_irqrestore(&dev->hpi.lock, flags);
}