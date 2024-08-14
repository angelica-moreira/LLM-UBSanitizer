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
struct mux {int /*<<< orphan*/  parent; struct iio_chan_spec const* chan; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  IIO_CHAN_INFO_RAW 128 
 int /*<<< orphan*/  iio_mux_deselect (struct mux*) ; 
 int iio_mux_select (struct mux*,int) ; 
 struct mux* iio_priv (struct iio_dev*) ; 
 int iio_write_channel_raw (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int mux_write_raw(struct iio_dev *indio_dev,
			 struct iio_chan_spec const *chan,
			 int val, int val2, long mask)
{
	struct mux *mux = iio_priv(indio_dev);
	int idx = chan - mux->chan;
	int ret;

	ret = iio_mux_select(mux, idx);
	if (ret < 0)
		return ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = iio_write_channel_raw(mux->parent, val);
		break;

	default:
		ret = -EINVAL;
	}

	iio_mux_deselect(mux);

	return ret;
}