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
struct comedi_subdevice {struct comedi_async* async; } ;
struct comedi_async {unsigned int munge_count; unsigned int buf_read_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  smp_rmb () ; 

unsigned int comedi_buf_read_n_available(struct comedi_subdevice *s)
{
	struct comedi_async *async = s->async;
	unsigned int num_bytes;

	if (!async)
		return 0;

	num_bytes = async->munge_count - async->buf_read_count;

	/*
	 * ensure the async buffer 'counts' are read before we
	 * attempt to read data from the buffer
	 */
	smp_rmb();

	return num_bytes;
}