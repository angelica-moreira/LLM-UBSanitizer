#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mcp4018_data {TYPE_1__* cfg; int /*<<< orphan*/  client; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;
typedef  int s32 ;
struct TYPE_2__ {int kohms; } ;

/* Variables and functions */
 int EINVAL ; 
#define  IIO_CHAN_INFO_RAW 129 
#define  IIO_CHAN_INFO_SCALE 128 
 int IIO_VAL_FRACTIONAL ; 
 int IIO_VAL_INT ; 
 int MCP4018_WIPER_MAX ; 
 int i2c_smbus_read_byte (int /*<<< orphan*/ ) ; 
 struct mcp4018_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int mcp4018_read_raw(struct iio_dev *indio_dev,
			    struct iio_chan_spec const *chan,
			    int *val, int *val2, long mask)
{
	struct mcp4018_data *data = iio_priv(indio_dev);
	s32 ret;

	switch (mask) {
	case IIO_CHAN_INFO_RAW:
		ret = i2c_smbus_read_byte(data->client);
		if (ret < 0)
			return ret;
		*val = ret;
		return IIO_VAL_INT;
	case IIO_CHAN_INFO_SCALE:
		*val = 1000 * data->cfg->kohms;
		*val2 = MCP4018_WIPER_MAX;
		return IIO_VAL_FRACTIONAL;
	}

	return -EINVAL;
}