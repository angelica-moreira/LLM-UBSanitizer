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
struct trace_array {int dummy; } ;

/* Variables and functions */
 struct trace_array* ctx_trace ; 
 int /*<<< orphan*/  start_nop_trace (struct trace_array*) ; 

__attribute__((used)) static int nop_trace_init(struct trace_array *tr)
{
	ctx_trace = tr;
	start_nop_trace(tr);
	return 0;
}