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
struct journal_head {int /*<<< orphan*/ * b_transaction; } ;

/* Variables and functions */
 int /*<<< orphan*/  __jbd2_journal_temp_unlink_buffer (struct journal_head*) ; 
 int /*<<< orphan*/  jbd2_journal_put_journal_head (struct journal_head*) ; 

__attribute__((used)) static void __jbd2_journal_unfile_buffer(struct journal_head *jh)
{
	__jbd2_journal_temp_unlink_buffer(jh);
	jh->b_transaction = NULL;
	jbd2_journal_put_journal_head(jh);
}