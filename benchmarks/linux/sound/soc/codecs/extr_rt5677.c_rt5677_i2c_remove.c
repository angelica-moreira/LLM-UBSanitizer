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
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rt5677_free_gpio (struct i2c_client*) ; 

__attribute__((used)) static int rt5677_i2c_remove(struct i2c_client *i2c)
{
	rt5677_free_gpio(i2c);

	return 0;
}