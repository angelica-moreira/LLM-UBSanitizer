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

/* Variables and functions */
 int /*<<< orphan*/  sctp_transport_walk_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sctp_transport_seq_stop(struct seq_file *seq, void *v)
{
	struct sctp_ht_iter *iter = seq->private;

	sctp_transport_walk_stop(&iter->hti);
}