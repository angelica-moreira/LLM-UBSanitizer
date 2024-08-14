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
struct msi001_dev {int /*<<< orphan*/  spi; } ;

/* Variables and functions */
 int spi_write (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int msi001_wreg(struct msi001_dev *dev, u32 data)
{
	/* Register format: 4 bits addr + 20 bits value */
	return spi_write(dev->spi, &data, 3);
}