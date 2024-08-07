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
struct sysc {scalar_t__* offsets; int revision; } ;

/* Variables and functions */
 size_t SYSC_REVISION ; 
 int sprintf (char*,char*,...) ; 

__attribute__((used)) static int sysc_show_rev(char *bufp, struct sysc *ddata)
{
	int len;

	if (ddata->offsets[SYSC_REVISION] < 0)
		return sprintf(bufp, ":NA");

	len = sprintf(bufp, ":%08x", ddata->revision);

	return len;
}