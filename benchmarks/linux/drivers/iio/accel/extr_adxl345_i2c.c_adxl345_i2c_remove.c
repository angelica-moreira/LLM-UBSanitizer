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
struct i2c_client {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int adxl345_core_remove (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int adxl345_i2c_remove(struct i2c_client *client)
{
	return adxl345_core_remove(&client->dev);
}