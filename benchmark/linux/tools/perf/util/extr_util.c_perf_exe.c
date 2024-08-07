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
 int readlink (char*,char*,int) ; 
 char* strcpy (char*,char*) ; 

char *perf_exe(char *buf, int len)
{
	int n = readlink("/proc/self/exe", buf, len);
	if (n > 0) {
		buf[n] = 0;
		return buf;
	}
	return strcpy(buf, "perf");
}