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
typedef  int /*<<< orphan*/  va_list ;
typedef  int ssize_t ;

/* Variables and functions */
 int vsnprintf (char*,size_t,char const*,int /*<<< orphan*/ ) ; 

int vscnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
       int i = vsnprintf(buf, size, fmt, args);
       ssize_t ssize = size;

       return (i >= ssize) ? (ssize - 1) : i;
}