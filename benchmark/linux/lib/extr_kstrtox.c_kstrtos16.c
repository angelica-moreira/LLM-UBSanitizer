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
typedef  long long s16 ;

/* Variables and functions */
 int ERANGE ; 
 int kstrtoll (char const*,unsigned int,long long*) ; 

int kstrtos16(const char *s, unsigned int base, s16 *res)
{
	long long tmp;
	int rv;

	rv = kstrtoll(s, base, &tmp);
	if (rv < 0)
		return rv;
	if (tmp != (s16)tmp)
		return -ERANGE;
	*res = tmp;
	return 0;
}