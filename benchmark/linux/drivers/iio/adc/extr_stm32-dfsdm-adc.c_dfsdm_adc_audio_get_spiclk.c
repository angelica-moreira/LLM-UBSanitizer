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
struct stm32_dfsdm_adc {int spi_freq; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct stm32_dfsdm_adc* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static ssize_t dfsdm_adc_audio_get_spiclk(struct iio_dev *indio_dev,
					  uintptr_t priv,
					  const struct iio_chan_spec *chan,
					  char *buf)
{
	struct stm32_dfsdm_adc *adc = iio_priv(indio_dev);

	return snprintf(buf, PAGE_SIZE, "%d\n", adc->spi_freq);
}