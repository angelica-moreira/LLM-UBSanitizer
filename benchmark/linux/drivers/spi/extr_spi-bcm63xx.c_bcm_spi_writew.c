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
typedef  int /*<<< orphan*/  u16 ;
struct bcm63xx_spi {scalar_t__* reg_offsets; scalar_t__ regs; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite16be (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline void bcm_spi_writew(struct bcm63xx_spi *bs,
				  u16 value, unsigned int offset)
{
#ifdef CONFIG_CPU_BIG_ENDIAN
	iowrite16be(value, bs->regs + bs->reg_offsets[offset]);
#else
	writew(value, bs->regs + bs->reg_offsets[offset]);
#endif
}