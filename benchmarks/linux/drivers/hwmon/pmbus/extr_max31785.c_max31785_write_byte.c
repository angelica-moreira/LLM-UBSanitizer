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
typedef  int /*<<< orphan*/  u8 ;
struct i2c_client {int dummy; } ;

/* Variables and functions */
 int ENODATA ; 
 int ENOTSUPP ; 
 int MAX31785_NR_PAGES ; 

__attribute__((used)) static int max31785_write_byte(struct i2c_client *client, int page, u8 value)
{
	if (page < MAX31785_NR_PAGES)
		return -ENODATA;

	return -ENOTSUPP;
}