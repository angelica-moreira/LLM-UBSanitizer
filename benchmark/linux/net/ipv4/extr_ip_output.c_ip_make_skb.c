#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct sock {int dummy; } ;
struct sk_buff_head {int dummy; } ;
struct sk_buff {int dummy; } ;
struct rtable {int dummy; } ;
struct ipcm_cookie {int dummy; } ;
struct inet_cork {int /*<<< orphan*/ * opt; scalar_t__ addr; scalar_t__ flags; } ;
struct flowi4 {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  task_frag; } ;

/* Variables and functions */
 struct sk_buff* ERR_PTR (int) ; 
 unsigned int MSG_PROBE ; 
 int __ip_append_data (struct sock*,struct flowi4*,struct sk_buff_head*,struct inet_cork*,int /*<<< orphan*/ *,int (*) (void*,char*,int,int,int,struct sk_buff*),void*,int,int,unsigned int) ; 
 int /*<<< orphan*/  __ip_flush_pending_frames (struct sock*,struct sk_buff_head*,struct inet_cork*) ; 
 struct sk_buff* __ip_make_skb (struct sock*,struct flowi4*,struct sk_buff_head*,struct inet_cork*) ; 
 int /*<<< orphan*/  __skb_queue_head_init (struct sk_buff_head*) ; 
 TYPE_1__* current ; 
 int ip_setup_cork (struct sock*,struct inet_cork*,struct ipcm_cookie*,struct rtable**) ; 

struct sk_buff *ip_make_skb(struct sock *sk,
			    struct flowi4 *fl4,
			    int getfrag(void *from, char *to, int offset,
					int len, int odd, struct sk_buff *skb),
			    void *from, int length, int transhdrlen,
			    struct ipcm_cookie *ipc, struct rtable **rtp,
			    struct inet_cork *cork, unsigned int flags)
{
	struct sk_buff_head queue;
	int err;

	if (flags & MSG_PROBE)
		return NULL;

	__skb_queue_head_init(&queue);

	cork->flags = 0;
	cork->addr = 0;
	cork->opt = NULL;
	err = ip_setup_cork(sk, cork, ipc, rtp);
	if (err)
		return ERR_PTR(err);

	err = __ip_append_data(sk, fl4, &queue, cork,
			       &current->task_frag, getfrag,
			       from, length, transhdrlen, flags);
	if (err) {
		__ip_flush_pending_frames(sk, &queue, cork);
		return ERR_PTR(err);
	}

	return __ip_make_skb(sk, fl4, &queue, cork);
}