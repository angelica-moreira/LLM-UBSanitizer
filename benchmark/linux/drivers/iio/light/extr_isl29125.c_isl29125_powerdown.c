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
struct isl29125_data {int conf1; int /*<<< orphan*/  client; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISL29125_CONF1 ; 
 int ISL29125_MODE_MASK ; 
 int ISL29125_MODE_PD ; 
 int i2c_smbus_write_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int isl29125_powerdown(struct isl29125_data *data)
{
	return i2c_smbus_write_byte_data(data->client, ISL29125_CONF1,
		(data->conf1 & ~ISL29125_MODE_MASK) | ISL29125_MODE_PD);
}