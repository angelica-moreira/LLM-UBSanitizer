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
struct spi_message {int dummy; } ;
struct spi_master {int dummy; } ;
struct lantiq_ssc_spi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rx_fifo_flush (struct lantiq_ssc_spi*) ; 
 struct lantiq_ssc_spi* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  tx_fifo_flush (struct lantiq_ssc_spi*) ; 

__attribute__((used)) static void lantiq_ssc_handle_err(struct spi_master *master,
				  struct spi_message *message)
{
	struct lantiq_ssc_spi *spi = spi_master_get_devdata(master);

	/* flush FIFOs on timeout */
	rx_fifo_flush(spi);
	tx_fifo_flush(spi);
}