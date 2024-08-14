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
struct bcm2835aux_spi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcm2835aux_spi_reset_hw (struct bcm2835aux_spi*) ; 
 struct bcm2835aux_spi* spi_master_get_devdata (struct spi_master*) ; 

__attribute__((used)) static int bcm2835aux_spi_unprepare_message(struct spi_master *master,
					    struct spi_message *msg)
{
	struct bcm2835aux_spi *bs = spi_master_get_devdata(master);

	bcm2835aux_spi_reset_hw(bs);

	return 0;
}