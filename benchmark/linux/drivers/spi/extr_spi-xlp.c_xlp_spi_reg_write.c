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
struct xlp_spi_priv {scalar_t__ base; } ;

/* Variables and functions */
 int SPI_CS_OFFSET ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void xlp_spi_reg_write(struct xlp_spi_priv *priv, int cs,
				int regoff, u32 val)
{
	writel(val, priv->base + regoff + cs * SPI_CS_OFFSET);
}