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
struct iio_dev {int /*<<< orphan*/  trig; } ;

/* Variables and functions */
 int /*<<< orphan*/  iio_trigger_poll_chained (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void at91_dma_buffer_done(void *data)
{
	struct iio_dev *indio_dev = data;

	iio_trigger_poll_chained(indio_dev->trig);
}