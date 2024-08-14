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
typedef  int u8 ;
struct spi_lm70llp {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int nCS ; 
 int parport_read_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parport_write_data (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void deassertCS(struct spi_lm70llp *pp)
{
	u8 data = parport_read_data(pp->port);

	data &= ~0x80;		/* pull D7/SI-out low while de-asserted */
	parport_write_data(pp->port, data | nCS);
}