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
struct stack_trace {unsigned long* entries; unsigned int max_entries; unsigned int skip; unsigned int nr_entries; } ;

/* Variables and functions */
 int /*<<< orphan*/  save_stack_trace (struct stack_trace*) ; 

unsigned int stack_trace_save(unsigned long *store, unsigned int size,
			      unsigned int skipnr)
{
	struct stack_trace trace = {
		.entries	= store,
		.max_entries	= size,
		.skip		= skipnr + 1,
	};

	save_stack_trace(&trace);
	return trace.nr_entries;
}