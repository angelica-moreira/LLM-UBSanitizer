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

/* Variables and functions */
 int __ui__warning (char*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int perf_tui__warning(const char *format, va_list args)
{
	return __ui__warning("Warning:", format, args);
}