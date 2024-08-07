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
struct tty_struct {int receive_room; struct syncppp* disc_data; TYPE_1__* ops; } ;
struct TYPE_4__ {int hdrlen; int speed; void* mtu; int /*<<< orphan*/ * ops; struct syncppp* private; } ;
struct syncppp {unsigned int* xaccm; unsigned int raccm; TYPE_2__ chan; int /*<<< orphan*/  dead_cmp; int /*<<< orphan*/  refcnt; int /*<<< orphan*/  tsk; int /*<<< orphan*/  rqueue; int /*<<< orphan*/  recv_lock; int /*<<< orphan*/  xmit_lock; void* mru; struct tty_struct* tty; } ;
struct TYPE_3__ {int /*<<< orphan*/ * write; } ;

/* Variables and functions */
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* PPP_MRU ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct syncppp*) ; 
 struct syncppp* kzalloc (int,int /*<<< orphan*/ ) ; 
 int ppp_register_channel (TYPE_2__*) ; 
 int /*<<< orphan*/  ppp_sync_process ; 
 int /*<<< orphan*/  refcount_set (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  skb_queue_head_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sync_ops ; 
 int /*<<< orphan*/  tasklet_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ,unsigned long) ; 
 int tty_get_baud_rate (struct tty_struct*) ; 

__attribute__((used)) static int
ppp_sync_open(struct tty_struct *tty)
{
	struct syncppp *ap;
	int err;
	int speed;

	if (tty->ops->write == NULL)
		return -EOPNOTSUPP;

	ap = kzalloc(sizeof(*ap), GFP_KERNEL);
	err = -ENOMEM;
	if (!ap)
		goto out;

	/* initialize the syncppp structure */
	ap->tty = tty;
	ap->mru = PPP_MRU;
	spin_lock_init(&ap->xmit_lock);
	spin_lock_init(&ap->recv_lock);
	ap->xaccm[0] = ~0U;
	ap->xaccm[3] = 0x60000000U;
	ap->raccm = ~0U;

	skb_queue_head_init(&ap->rqueue);
	tasklet_init(&ap->tsk, ppp_sync_process, (unsigned long) ap);

	refcount_set(&ap->refcnt, 1);
	init_completion(&ap->dead_cmp);

	ap->chan.private = ap;
	ap->chan.ops = &sync_ops;
	ap->chan.mtu = PPP_MRU;
	ap->chan.hdrlen = 2;	/* for A/C bytes */
	speed = tty_get_baud_rate(tty);
	ap->chan.speed = speed;
	err = ppp_register_channel(&ap->chan);
	if (err)
		goto out_free;

	tty->disc_data = ap;
	tty->receive_room = 65536;
	return 0;

 out_free:
	kfree(ap);
 out:
	return err;
}