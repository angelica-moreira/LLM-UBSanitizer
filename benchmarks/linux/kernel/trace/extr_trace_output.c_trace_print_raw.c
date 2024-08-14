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
struct trace_iterator {int /*<<< orphan*/  seq; int /*<<< orphan*/  ent; } ;
struct trace_event {int dummy; } ;
struct print_entry {int /*<<< orphan*/  buf; int /*<<< orphan*/  ip; } ;
typedef  enum print_line_t { ____Placeholder_print_line_t } print_line_t ;

/* Variables and functions */
 int /*<<< orphan*/  trace_assign_type (struct print_entry*,int /*<<< orphan*/ ) ; 
 int trace_handle_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_seq_printf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum print_line_t trace_print_raw(struct trace_iterator *iter, int flags,
					 struct trace_event *event)
{
	struct print_entry *field;

	trace_assign_type(field, iter->ent);

	trace_seq_printf(&iter->seq, "# %lx %s", field->ip, field->buf);

	return trace_handle_return(&iter->seq);
}