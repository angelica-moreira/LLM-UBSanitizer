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
struct file {int /*<<< orphan*/  f_lock; } ;
struct eventpoll {TYPE_2__* user; int /*<<< orphan*/  lock; int /*<<< orphan*/  rbr; } ;
struct TYPE_3__ {struct file* file; } ;
struct epitem {int /*<<< orphan*/  rcu; int /*<<< orphan*/  rdllink; int /*<<< orphan*/  rbn; int /*<<< orphan*/  fllink; TYPE_1__ ffd; } ;
struct TYPE_4__ {int /*<<< orphan*/  epoll_watches; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_long_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  call_rcu (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ ep_is_linked (struct epitem*) ; 
 int /*<<< orphan*/  ep_unregister_pollwait (struct eventpoll*,struct epitem*) ; 
 int /*<<< orphan*/  ep_wakeup_source (struct epitem*) ; 
 int /*<<< orphan*/  epi_rcu_free ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_rcu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lockdep_assert_irqs_enabled () ; 
 int /*<<< orphan*/  rb_erase_cached (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wakeup_source_unregister (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ep_remove(struct eventpoll *ep, struct epitem *epi)
{
	struct file *file = epi->ffd.file;

	lockdep_assert_irqs_enabled();

	/*
	 * Removes poll wait queue hooks.
	 */
	ep_unregister_pollwait(ep, epi);

	/* Remove the current item from the list of epoll hooks */
	spin_lock(&file->f_lock);
	list_del_rcu(&epi->fllink);
	spin_unlock(&file->f_lock);

	rb_erase_cached(&epi->rbn, &ep->rbr);

	write_lock_irq(&ep->lock);
	if (ep_is_linked(epi))
		list_del_init(&epi->rdllink);
	write_unlock_irq(&ep->lock);

	wakeup_source_unregister(ep_wakeup_source(epi));
	/*
	 * At this point it is safe to free the eventpoll item. Use the union
	 * field epi->rcu, since we are trying to minimize the size of
	 * 'struct epitem'. The 'rbn' field is no longer in use. Protected by
	 * ep->mtx. The rcu read side, reverse_path_check_proc(), does not make
	 * use of the rbn field.
	 */
	call_rcu(&epi->rcu, epi_rcu_free);

	atomic_long_dec(&ep->user->epoll_watches);

	return 0;
}