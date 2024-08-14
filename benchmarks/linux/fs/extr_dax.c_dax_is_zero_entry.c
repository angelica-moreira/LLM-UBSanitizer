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
 int DAX_ZERO_PAGE ; 
 int xa_to_value (void*) ; 

__attribute__((used)) static int dax_is_zero_entry(void *entry)
{
	return xa_to_value(entry) & DAX_ZERO_PAGE;
}