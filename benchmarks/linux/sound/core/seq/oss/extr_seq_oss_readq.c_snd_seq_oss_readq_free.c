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
struct seq_oss_readq {scalar_t__ qlen; int head; int maxlen; } ;

/* Variables and functions */

void
snd_seq_oss_readq_free(struct seq_oss_readq *q)
{
	if (q->qlen > 0) {
		q->head = (q->head + 1) % q->maxlen;
		q->qlen--;
	}
}