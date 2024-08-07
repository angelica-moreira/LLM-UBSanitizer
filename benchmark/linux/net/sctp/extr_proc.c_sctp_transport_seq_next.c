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
struct seq_file {struct sctp_ht_iter* private; } ;
struct sctp_ht_iter {int /*<<< orphan*/  hti; } ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 void* sctp_transport_get_next (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_file_net (struct seq_file*) ; 

__attribute__((used)) static void *sctp_transport_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
	struct sctp_ht_iter *iter = seq->private;

	++*pos;

	return sctp_transport_get_next(seq_file_net(seq), &iter->hti);
}