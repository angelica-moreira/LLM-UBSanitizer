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
typedef  int /*<<< orphan*/  u16 ;
struct cx231xx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AFE_DEVICE_ADDRESS ; 
 int cx231xx_write_i2c_data (struct cx231xx*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int afe_write_byte(struct cx231xx *dev, u16 saddr, u8 data)
{
	return cx231xx_write_i2c_data(dev, AFE_DEVICE_ADDRESS,
					saddr, 2, data, 1);
}