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
struct videobuf_queue {scalar_t__ reading; scalar_t__ streaming; } ;

/* Variables and functions */
 int /*<<< orphan*/  __videobuf_read_stop (struct videobuf_queue*) ; 
 int /*<<< orphan*/  __videobuf_streamoff (struct videobuf_queue*) ; 
 int /*<<< orphan*/  videobuf_queue_lock (struct videobuf_queue*) ; 
 int /*<<< orphan*/  videobuf_queue_unlock (struct videobuf_queue*) ; 

void videobuf_stop(struct videobuf_queue *q)
{
	videobuf_queue_lock(q);

	if (q->streaming)
		__videobuf_streamoff(q);

	if (q->reading)
		__videobuf_read_stop(q);

	videobuf_queue_unlock(q);
}