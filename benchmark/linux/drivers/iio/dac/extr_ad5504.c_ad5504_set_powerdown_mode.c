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
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;
struct ad5504_state {unsigned int pwr_down_mode; } ;

/* Variables and functions */
 struct ad5504_state* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int ad5504_set_powerdown_mode(struct iio_dev *indio_dev,
	const struct iio_chan_spec *chan, unsigned int mode)
{
	struct ad5504_state *st = iio_priv(indio_dev);

	st->pwr_down_mode = mode;

	return 0;
}