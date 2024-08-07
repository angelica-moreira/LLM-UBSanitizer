#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {unsigned int len; } ;
struct trace_seq {int full; TYPE_1__ seq; } ;

/* Variables and functions */
 unsigned int TRACE_SEQ_BUF_LEFT (struct trace_seq*) ; 
 int /*<<< orphan*/  __trace_seq_init (struct trace_seq*) ; 
 int /*<<< orphan*/  seq_buf_has_overflowed (TYPE_1__*) ; 
 int /*<<< orphan*/  seq_buf_putmem_hex (TYPE_1__*,void const*,unsigned int) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

void trace_seq_putmem_hex(struct trace_seq *s, const void *mem,
			 unsigned int len)
{
	unsigned int save_len = s->seq.len;

	if (s->full)
		return;

	__trace_seq_init(s);

	/* Each byte is represented by two chars */
	if (len * 2 > TRACE_SEQ_BUF_LEFT(s)) {
		s->full = 1;
		return;
	}

	/* The added spaces can still cause an overflow */
	seq_buf_putmem_hex(&s->seq, mem, len);

	if (unlikely(seq_buf_has_overflowed(&s->seq))) {
		s->seq.len = save_len;
		s->full = 1;
		return;
	}
}