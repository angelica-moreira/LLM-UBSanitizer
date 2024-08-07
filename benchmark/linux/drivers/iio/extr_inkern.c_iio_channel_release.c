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
struct iio_channel {int /*<<< orphan*/  indio_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  iio_device_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct iio_channel*) ; 

void iio_channel_release(struct iio_channel *channel)
{
	if (!channel)
		return;
	iio_device_put(channel->indio_dev);
	kfree(channel);
}