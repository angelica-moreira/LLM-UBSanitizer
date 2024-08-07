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
typedef  scalar_t__ u16 ;
struct rspi_data {scalar_t__ addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite8 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void rspi_write8(const struct rspi_data *rspi, u8 data, u16 offset)
{
	iowrite8(data, rspi->addr + offset);
}