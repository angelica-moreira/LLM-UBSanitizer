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
struct trace_buffer {int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,int /*<<< orphan*/ ,struct trace_buffer*) ; 

void trace_print_location(struct trace_buffer *tb)
{
	printf("Trace buffer 0x%llx bytes @ %p\n", tb->size, tb);
}