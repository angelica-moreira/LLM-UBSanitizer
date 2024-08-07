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
struct mga_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mga_i2c_set_gpio (struct mga_device*,int,int) ; 

__attribute__((used)) static inline void mga_i2c_set(struct mga_device *mdev, int mask, int state)
{
	if (state)
		state = 0;
	else
		state = mask;
	mga_i2c_set_gpio(mdev, ~mask, state);
}