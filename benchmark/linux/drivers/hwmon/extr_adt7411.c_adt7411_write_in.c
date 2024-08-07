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
typedef  int /*<<< orphan*/  u32 ;
struct device {int dummy; } ;

/* Variables and functions */
 int adt7411_write_in_chan (struct device*,int /*<<< orphan*/ ,int,long) ; 
 int adt7411_write_in_vdd (struct device*,int /*<<< orphan*/ ,long) ; 

__attribute__((used)) static int adt7411_write_in(struct device *dev, u32 attr, int channel,
			    long val)
{
	if (channel == 0)
		return adt7411_write_in_vdd(dev, attr, val);
	else
		return adt7411_write_in_chan(dev, attr, channel, val);
}