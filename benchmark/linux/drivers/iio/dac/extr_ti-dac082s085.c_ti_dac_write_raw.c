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
struct ti_dac_chip {int* val; int resolution; int /*<<< orphan*/  lock; int /*<<< orphan*/  powerdown; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {size_t channel; } ;

/* Variables and functions */
 int EBUSY ; 
 int EINVAL ; 
#define  IIO_CHAN_INFO_RAW 128 
 int /*<<< orphan*/  WRITE_AND_UPDATE (size_t) ; 
 struct ti_dac_chip* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int ti_dac_cmd (struct ti_dac_chip*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ti_dac_write_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int val, int val2, long mask)
{
	struct ti_dac_chip *ti_dac = iio_priv(indio_dev);
	int ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		if (ti_dac->val[chan->channel] == val)
			return 0;

		if (val >= (1 << ti_dac->resolution) || val < 0)
			return -EINVAL;

		if (ti_dac->powerdown)
			return -EBUSY;

		mutex_lock(&ti_dac->lock);
		ret = ti_dac_cmd(ti_dac, WRITE_AND_UPDATE(chan->channel), val);
		if (!ret)
			ti_dac->val[chan->channel] = val;
		mutex_unlock(&ti_dac->lock);
		break;

	default:
		ret = -EINVAL;
	}

	return ret;
}