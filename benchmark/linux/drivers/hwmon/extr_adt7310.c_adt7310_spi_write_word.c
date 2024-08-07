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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct spi_device {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  AD7310_COMMAND (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_unaligned_be16 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int spi_write (struct spi_device*,int /*<<< orphan*/ *,int) ; 
 struct spi_device* to_spi_device (struct device*) ; 

__attribute__((used)) static int adt7310_spi_write_word(struct device *dev, u8 reg, u16 data)
{
	struct spi_device *spi = to_spi_device(dev);
	u8 buf[3];

	buf[0] = AD7310_COMMAND(reg);
	put_unaligned_be16(data, &buf[1]);

	return spi_write(spi, buf, sizeof(buf));
}