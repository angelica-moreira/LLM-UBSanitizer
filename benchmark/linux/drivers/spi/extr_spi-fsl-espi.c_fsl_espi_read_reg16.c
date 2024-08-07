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
struct fsl_espi {scalar_t__ reg_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  ioread16be (scalar_t__) ; 

__attribute__((used)) static inline u16 fsl_espi_read_reg16(struct fsl_espi *espi, int offset)
{
	return ioread16be(espi->reg_base + offset);
}