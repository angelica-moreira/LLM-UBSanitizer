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

/* Variables and functions */
 int /*<<< orphan*/  iio_priv (struct iio_dev*) ; 
 int st_uvis25_set_enable (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int st_uvis25_buffer_postdisable(struct iio_dev *iio_dev)
{
	return st_uvis25_set_enable(iio_priv(iio_dev), false);
}