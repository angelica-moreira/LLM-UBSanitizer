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
struct seq_oss_timer {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct seq_oss_timer*) ; 
 int /*<<< orphan*/  snd_seq_oss_timer_stop (struct seq_oss_timer*) ; 

void
snd_seq_oss_timer_delete(struct seq_oss_timer *rec)
{
	if (rec) {
		snd_seq_oss_timer_stop(rec);
		kfree(rec);
	}
}