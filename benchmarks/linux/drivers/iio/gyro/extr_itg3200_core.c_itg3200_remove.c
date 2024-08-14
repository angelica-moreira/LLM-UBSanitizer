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
struct i2c_client {scalar_t__ irq; } ;

/* Variables and functions */
 struct iio_dev* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  iio_device_unregister (struct iio_dev*) ; 
 int /*<<< orphan*/  itg3200_buffer_unconfigure (struct iio_dev*) ; 
 int /*<<< orphan*/  itg3200_remove_trigger (struct iio_dev*) ; 

__attribute__((used)) static int itg3200_remove(struct i2c_client *client)
{
	struct iio_dev *indio_dev = i2c_get_clientdata(client);

	iio_device_unregister(indio_dev);

	if (client->irq)
		itg3200_remove_trigger(indio_dev);

	itg3200_buffer_unconfigure(indio_dev);

	return 0;
}