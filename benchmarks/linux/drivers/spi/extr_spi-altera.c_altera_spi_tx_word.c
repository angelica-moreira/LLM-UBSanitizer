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
struct altera_spi {unsigned int* tx; int bytes_per_word; size_t count; scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ ALTERA_SPI_TXDATA ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static void altera_spi_tx_word(struct altera_spi *hw)
{
	unsigned int txd = 0;

	if (hw->tx) {
		switch (hw->bytes_per_word) {
		case 1:
			txd = hw->tx[hw->count];
			break;
		case 2:
			txd = (hw->tx[hw->count * 2]
				| (hw->tx[hw->count * 2 + 1] << 8));
			break;
		}
	}

	writel(txd, hw->base + ALTERA_SPI_TXDATA);
}