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
struct cs42l42_private {int /*<<< orphan*/  reset_gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cs42l42_private* i2c_get_clientdata (struct i2c_client*) ; 

__attribute__((used)) static int cs42l42_i2c_remove(struct i2c_client *i2c_client)
{
	struct cs42l42_private *cs42l42 = i2c_get_clientdata(i2c_client);

	/* Hold down reset */
	gpiod_set_value_cansleep(cs42l42->reset_gpio, 0);

	return 0;
}