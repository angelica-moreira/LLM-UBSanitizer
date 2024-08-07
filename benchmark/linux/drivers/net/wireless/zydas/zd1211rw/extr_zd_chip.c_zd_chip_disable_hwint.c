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
struct zd_chip {int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int disable_hwint (struct zd_chip*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int zd_chip_disable_hwint(struct zd_chip *chip)
{
	int r;

	mutex_lock(&chip->mutex);
	r = disable_hwint(chip);
	mutex_unlock(&chip->mutex);
	return r;
}