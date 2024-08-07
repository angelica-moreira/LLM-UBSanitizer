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
struct iio_chan_spec {int channel; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  IIO_TEMP ; 

__attribute__((used)) static void ad7280_temp_channel_init(struct iio_chan_spec *chan, int i)
{
	chan->type = IIO_TEMP;
	chan->channel = i;
}