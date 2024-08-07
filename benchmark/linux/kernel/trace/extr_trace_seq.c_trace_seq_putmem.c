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
struct trace_seq {int full; int /*<<< orphan*/  seq; } ;

/* Variables and functions */
 unsigned int TRACE_SEQ_BUF_LEFT (struct trace_seq*) ; 
 int /*<<< orphan*/  __trace_seq_init (struct trace_seq*) ; 
 int /*<<< orphan*/  seq_buf_putmem (int /*<<< orphan*/ *,void const*,unsigned int) ; 

void trace_seq_putmem(struct trace_seq *s, const void *mem, unsigned int len)
{
	if (s->full)
		return;

	__trace_seq_init(s);

	if (len > TRACE_SEQ_BUF_LEFT(s)) {
		s->full = 1;
		return;
	}

	seq_buf_putmem(&s->seq, mem, len);
}