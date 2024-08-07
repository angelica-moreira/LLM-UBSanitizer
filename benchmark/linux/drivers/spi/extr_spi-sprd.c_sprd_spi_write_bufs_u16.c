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
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sprd_spi {int tx_buf; scalar_t__ base; } ;

/* Variables and functions */
 scalar_t__ SPRD_SPI_TXD ; 
 int /*<<< orphan*/  writew_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int sprd_spi_write_bufs_u16(struct sprd_spi *ss, u32 len)
{
	u16 *tx_p = (u16 *)ss->tx_buf;
	int i;

	for (i = 0; i < len; i++)
		writew_relaxed(tx_p[i], ss->base + SPRD_SPI_TXD);

	ss->tx_buf += i << 1;
	return i << 1;
}