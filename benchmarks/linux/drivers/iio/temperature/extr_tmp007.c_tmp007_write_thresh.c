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
struct tmp007_data {int /*<<< orphan*/  client; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int channel2; } ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_info { ____Placeholder_iio_event_info } iio_event_info ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 int EINVAL ; 
 int IIO_EV_DIR_RISING ; 
#define  IIO_MOD_TEMP_AMBIENT 129 
#define  IIO_MOD_TEMP_OBJECT 128 
 int /*<<< orphan*/  TMP007_TDIE_HIGH_LIMIT ; 
 int /*<<< orphan*/  TMP007_TDIE_LOW_LIMIT ; 
 int /*<<< orphan*/  TMP007_TOBJ_HIGH_LIMIT ; 
 int /*<<< orphan*/  TMP007_TOBJ_LOW_LIMIT ; 
 int i2c_smbus_write_word_swapped (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct tmp007_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int tmp007_write_thresh(struct iio_dev *indio_dev,
		const struct iio_chan_spec *chan, enum iio_event_type type,
		enum iio_event_direction dir, enum iio_event_info info,
		int val, int val2)
{
	struct tmp007_data *data = iio_priv(indio_dev);
	u8 reg;

	switch (chan->channel2) {
	case IIO_MOD_TEMP_AMBIENT:
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TDIE_HIGH_LIMIT;
		else
			reg = TMP007_TDIE_LOW_LIMIT;
		break;
	case IIO_MOD_TEMP_OBJECT:
		if (dir == IIO_EV_DIR_RISING)
			reg = TMP007_TOBJ_HIGH_LIMIT;
		else
			reg = TMP007_TOBJ_LOW_LIMIT;
		break;
	default:
		return -EINVAL;
	}

	/* Full scale threshold value is +/- 256 degree Celsius */
	if (val < -256 || val > 255)
		return -EINVAL;

	/* Shift length 7 bits = 6(15:6) + 1(0.5 LSB) */
	return i2c_smbus_write_word_swapped(data->client, reg, (val << 7));
}