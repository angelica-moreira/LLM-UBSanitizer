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
 int parameqn (char const*,char const*,scalar_t__) ; 
 scalar_t__ strlen (char const*) ; 

bool parameq(const char *a, const char *b)
{
	return parameqn(a, b, strlen(a)+1);
}