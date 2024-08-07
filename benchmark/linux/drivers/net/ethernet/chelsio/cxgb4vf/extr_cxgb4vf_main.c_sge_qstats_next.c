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
struct seq_file {int /*<<< orphan*/  private; } ;
typedef  int loff_t ;

/* Variables and functions */
 int sge_qstats_entries (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *sge_qstats_next(struct seq_file *seq, void *v, loff_t *pos)
{
	int entries = sge_qstats_entries(seq->private);

	(*pos)++;
	return *pos < entries ? (void *)((uintptr_t)*pos + 1) : NULL;
}