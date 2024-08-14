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
struct spi_device {int dummy; } ;
struct iio_dev {int dummy; } ;
struct adis16480 {int /*<<< orphan*/  ext_clk; int /*<<< orphan*/  adis; } ;

/* Variables and functions */
 int /*<<< orphan*/  adis16480_stop_device (struct iio_dev*) ; 
 int /*<<< orphan*/  adis_cleanup_buffer_and_trigger (int /*<<< orphan*/ *,struct iio_dev*) ; 
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 struct adis16480* iio_priv (struct iio_dev*) ; 
 struct iio_dev* spi_get_drvdata (struct spi_device*) ; 

__attribute__((used)) static int adis16480_remove(struct spi_device *spi)
{
	struct iio_dev *indio_dev = spi_get_drvdata(spi);
	struct adis16480 *st = iio_priv(indio_dev);

	iio_device_unregister(indio_dev);
	adis16480_stop_device(indio_dev);

	adis_cleanup_buffer_and_trigger(&st->adis, indio_dev);
	clk_disable_unprepare(st->ext_clk);

	return 0;
}