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
 int /*<<< orphan*/  ams_i2c_driver ; 
 int /*<<< orphan*/  i2c_del_driver (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ams_i2c_exit(void)
{
	i2c_del_driver(&ams_i2c_driver);
}