#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {TYPE_2__* t_journal; struct journal_head* t_reserved_list; struct journal_head* t_shadow_list; struct journal_head* t_forget; struct journal_head* t_buffers; int /*<<< orphan*/  t_nr_buffers; } ;
typedef  TYPE_1__ transaction_t ;
struct journal_head {int b_jlist; TYPE_1__* b_transaction; } ;
struct buffer_head {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  j_list_lock; } ;

/* Variables and functions */
#define  BJ_Forget 132 
#define  BJ_Metadata 131 
#define  BJ_None 130 
#define  BJ_Reserved 129 
#define  BJ_Shadow 128 
 int BJ_Types ; 
 int /*<<< orphan*/  J_ASSERT_JH (struct journal_head*,int) ; 
 int /*<<< orphan*/  __blist_del_buffer (struct journal_head**,struct journal_head*) ; 
 int /*<<< orphan*/  assert_spin_locked (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_buffer_jbddirty (struct buffer_head*) ; 
 scalar_t__ is_journal_aborted (TYPE_2__*) ; 
 int jbd_is_locked_bh_state (struct buffer_head*) ; 
 struct buffer_head* jh2bh (struct journal_head*) ; 
 int /*<<< orphan*/  mark_buffer_dirty (struct buffer_head*) ; 
 scalar_t__ test_clear_buffer_jbddirty (struct buffer_head*) ; 

__attribute__((used)) static void __jbd2_journal_temp_unlink_buffer(struct journal_head *jh)
{
	struct journal_head **list = NULL;
	transaction_t *transaction;
	struct buffer_head *bh = jh2bh(jh);

	J_ASSERT_JH(jh, jbd_is_locked_bh_state(bh));
	transaction = jh->b_transaction;
	if (transaction)
		assert_spin_locked(&transaction->t_journal->j_list_lock);

	J_ASSERT_JH(jh, jh->b_jlist < BJ_Types);
	if (jh->b_jlist != BJ_None)
		J_ASSERT_JH(jh, transaction != NULL);

	switch (jh->b_jlist) {
	case BJ_None:
		return;
	case BJ_Metadata:
		transaction->t_nr_buffers--;
		J_ASSERT_JH(jh, transaction->t_nr_buffers >= 0);
		list = &transaction->t_buffers;
		break;
	case BJ_Forget:
		list = &transaction->t_forget;
		break;
	case BJ_Shadow:
		list = &transaction->t_shadow_list;
		break;
	case BJ_Reserved:
		list = &transaction->t_reserved_list;
		break;
	}

	__blist_del_buffer(list, jh);
	jh->b_jlist = BJ_None;
	if (transaction && is_journal_aborted(transaction->t_journal))
		clear_buffer_jbddirty(bh);
	else if (test_clear_buffer_jbddirty(bh))
		mark_buffer_dirty(bh);	/* Expose it to the VM */
}