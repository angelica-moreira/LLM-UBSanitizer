#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct bmc150_accel_data {scalar_t__ bw_bits; } ;
struct TYPE_3__ {scalar_t__ bw_bits; int val; int val2; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 int IIO_VAL_INT_PLUS_MICRO ; 
 TYPE_1__* bmc150_accel_samp_freq_table ; 

__attribute__((used)) static int bmc150_accel_get_bw(struct bmc150_accel_data *data, int *val,
			       int *val2)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(bmc150_accel_samp_freq_table); ++i) {
		if (bmc150_accel_samp_freq_table[i].bw_bits == data->bw_bits) {
			*val = bmc150_accel_samp_freq_table[i].val;
			*val2 = bmc150_accel_samp_freq_table[i].val2;
			return IIO_VAL_INT_PLUS_MICRO;
		}
	}

	return -EINVAL;
}