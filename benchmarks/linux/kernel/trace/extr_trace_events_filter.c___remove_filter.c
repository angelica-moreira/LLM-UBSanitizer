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
struct trace_event_file {int /*<<< orphan*/  filter; } ;

/* Variables and functions */
 int /*<<< orphan*/  filter_disable (struct trace_event_file*) ; 
 int /*<<< orphan*/  remove_filter_string (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void __remove_filter(struct trace_event_file *file)
{
	filter_disable(file);
	remove_filter_string(file->filter);
}