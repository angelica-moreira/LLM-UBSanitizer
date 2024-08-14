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
struct config_item {int dummy; } ;
struct acpi_table_header {int /*<<< orphan*/  oem_table_id; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 char* ACPI_OEM_TABLE_ID_SIZE ; 
 int /*<<< orphan*/  EINVAL ; 
 struct acpi_table_header* get_header (struct config_item*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t acpi_table_oem_table_id_show(struct config_item *cfg, char *str)
{
	struct acpi_table_header *h = get_header(cfg);

	if (!h)
		return -EINVAL;

	return sprintf(str, "%.*s\n", ACPI_OEM_TABLE_ID_SIZE, h->oem_table_id);
}