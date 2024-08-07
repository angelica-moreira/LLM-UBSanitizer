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
struct spi_device {int dummy; } ;
typedef  enum mantisse { ____Placeholder_mantisse } mantisse ;

/* Variables and functions */
 int /*<<< orphan*/  REG_AFCBW ; 
 int rf69_set_bandwidth_intern (struct spi_device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int rf69_set_bandwidth_during_afc(struct spi_device *spi,
				  enum mantisse mantisse,
				  u8 exponent)
{
	return rf69_set_bandwidth_intern(spi, REG_AFCBW, mantisse, exponent);
}