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
struct i2c_dev_desc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct i2c_dev_desc*) ; 

__attribute__((used)) static void i3c_master_free_i2c_dev(struct i2c_dev_desc *dev)
{
	kfree(dev);
}