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
typedef  int u32 ;
typedef  int /*<<< orphan*/  TW_Device_Extension ;

/* Variables and functions */
 int HZ ; 
 int /*<<< orphan*/  TW_STATUS_REG_ADDR (int /*<<< orphan*/ *) ; 
 int inl (int /*<<< orphan*/ ) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  msleep (int) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 scalar_t__ tw_check_bits (int) ; 
 int /*<<< orphan*/  tw_decode_bits (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tw_poll_status(TW_Device_Extension *tw_dev, u32 flag, int seconds)
{
	u32 status_reg_value;
	unsigned long before;
	int retval = 1;

	status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));
	before = jiffies;

	if (tw_check_bits(status_reg_value))
		tw_decode_bits(tw_dev, status_reg_value, 0);

	while ((status_reg_value & flag) != flag) {
		status_reg_value = inl(TW_STATUS_REG_ADDR(tw_dev));

		if (tw_check_bits(status_reg_value))
			tw_decode_bits(tw_dev, status_reg_value, 0);

		if (time_after(jiffies, before + HZ * seconds))
			goto out;

		msleep(50);
	}
	retval = 0;
out:
	return retval;
}