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
struct allegro_dev {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  AL5_MCU_STA ; 
 unsigned int AL5_MCU_STA_SLEEP ; 
 int /*<<< orphan*/  AL5_MCU_WAKEUP ; 
 int /*<<< orphan*/  BIT (int /*<<< orphan*/ ) ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  cpu_relax () ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int) ; 
 scalar_t__ regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 

__attribute__((used)) static int allegro_mcu_start(struct allegro_dev *dev)
{
	unsigned long timeout;
	unsigned int status;
	int err;

	err = regmap_write(dev->regmap, AL5_MCU_WAKEUP, BIT(0));
	if (err)
		return err;

	timeout = jiffies + msecs_to_jiffies(100);
	while (regmap_read(dev->regmap, AL5_MCU_STA, &status) == 0 &&
	       status == AL5_MCU_STA_SLEEP) {
		if (time_after(jiffies, timeout))
			return -ETIMEDOUT;
		cpu_relax();
	}

	err = regmap_write(dev->regmap, AL5_MCU_WAKEUP, 0);
	if (err)
		return err;

	return 0;
}