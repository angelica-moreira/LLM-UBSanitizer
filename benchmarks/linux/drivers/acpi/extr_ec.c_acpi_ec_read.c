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
struct transaction {int wlen; int rlen; int /*<<< orphan*/ * rdata; int /*<<< orphan*/ * wdata; int /*<<< orphan*/  command; } ;
struct acpi_ec {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_EC_COMMAND_READ ; 
 int acpi_ec_transaction (struct acpi_ec*,struct transaction*) ; 

__attribute__((used)) static int acpi_ec_read(struct acpi_ec *ec, u8 address, u8 *data)
{
	int result;
	u8 d;
	struct transaction t = {.command = ACPI_EC_COMMAND_READ,
				.wdata = &address, .rdata = &d,
				.wlen = 1, .rlen = 1};

	result = acpi_ec_transaction(ec, &t);
	*data = d;
	return result;
}