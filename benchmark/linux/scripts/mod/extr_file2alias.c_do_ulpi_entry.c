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

/* Variables and functions */
 int /*<<< orphan*/  DEF_FIELD (void*,int /*<<< orphan*/ ,int) ; 
 int product ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,int) ; 
 int /*<<< orphan*/  ulpi_device_id ; 
 int vendor ; 

__attribute__((used)) static int do_ulpi_entry(const char *filename, void *symval,
			 char *alias)
{
	DEF_FIELD(symval, ulpi_device_id, vendor);
	DEF_FIELD(symval, ulpi_device_id, product);

	sprintf(alias, "ulpi:v%04xp%04x", vendor, product);

	return 1;
}