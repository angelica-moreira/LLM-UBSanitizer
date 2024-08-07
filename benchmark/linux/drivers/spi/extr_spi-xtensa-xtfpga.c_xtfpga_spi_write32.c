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
typedef  int /*<<< orphan*/  u32 ;
struct xtfpga_spi {unsigned int regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_writel (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void xtfpga_spi_write32(const struct xtfpga_spi *spi,
				      unsigned addr, u32 val)
{
	__raw_writel(val, spi->regs + addr);
}