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
typedef  int u8 ;
struct bq24190_dev_info {int dummy; } ;

/* Variables and functions */
 int bq24190_read (struct bq24190_dev_info*,int,int*) ; 
 int bq24190_write (struct bq24190_dev_info*,int,int) ; 

__attribute__((used)) static int bq24190_write_mask(struct bq24190_dev_info *bdi, u8 reg,
		u8 mask, u8 shift, u8 data)
{
	u8 v;
	int ret;

	ret = bq24190_read(bdi, reg, &v);
	if (ret < 0)
		return ret;

	v &= ~mask;
	v |= ((data << shift) & mask);

	return bq24190_write(bdi, reg, v);
}