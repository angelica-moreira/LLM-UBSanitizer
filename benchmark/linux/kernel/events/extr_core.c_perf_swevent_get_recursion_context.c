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
struct swevent_htable {int /*<<< orphan*/  recursion; } ;

/* Variables and functions */
 int get_recursion_context (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  swevent_htable ; 
 struct swevent_htable* this_cpu_ptr (int /*<<< orphan*/ *) ; 

int perf_swevent_get_recursion_context(void)
{
	struct swevent_htable *swhash = this_cpu_ptr(&swevent_htable);

	return get_recursion_context(swhash->recursion);
}