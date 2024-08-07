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

/* Variables and functions */
 int /*<<< orphan*/  msleep_interruptible (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

void mma9551_sleep(int freq)
{
	int sleep_val = 1000 / freq;

	if (sleep_val < 20)
		usleep_range(sleep_val * 1000, 20000);
	else
		msleep_interruptible(sleep_val);
}