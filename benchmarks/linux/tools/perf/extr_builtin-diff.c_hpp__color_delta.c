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
struct perf_hpp_fmt {int dummy; } ;
struct perf_hpp {int dummy; } ;
struct hist_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMPUTE_DELTA ; 
 int __hpp__color_compare (struct perf_hpp_fmt*,struct perf_hpp*,struct hist_entry*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hpp__color_delta(struct perf_hpp_fmt *fmt,
			struct perf_hpp *hpp, struct hist_entry *he)
{
	return __hpp__color_compare(fmt, hpp, he, COMPUTE_DELTA);
}