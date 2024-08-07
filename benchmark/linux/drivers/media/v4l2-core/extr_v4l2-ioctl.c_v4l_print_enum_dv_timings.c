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
struct v4l2_enum_dv_timings {int /*<<< orphan*/  timings; int /*<<< orphan*/  index; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_cont (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  v4l_print_dv_timings (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void v4l_print_enum_dv_timings(const void *arg, bool write_only)
{
	const struct v4l2_enum_dv_timings *p = arg;

	pr_cont("index=%u, ", p->index);
	v4l_print_dv_timings(&p->timings, write_only);
}