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
 char* strchr (char*,char) ; 
 int strlen (char*) ; 
 double strtod (char*,char**) ; 

__attribute__((used)) static int parse_percent(double *pcnt, char *str)
{
	char *c, *endptr;
	double d;

	c = strchr(str, '%');
	if (c)
		*c = '\0';
	else
		return -1;

	d = strtod(str, &endptr);
	if (endptr != str + strlen(str))
		return -1;

	*pcnt = d / 100.0;
	return 0;
}