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
struct spi_device {int /*<<< orphan*/  master; } ;
struct altera_spi {int dummy; } ;

/* Variables and functions */
 struct altera_spi* spi_master_get_devdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct altera_spi *altera_spi_to_hw(struct spi_device *sdev)
{
	return spi_master_get_devdata(sdev->master);
}