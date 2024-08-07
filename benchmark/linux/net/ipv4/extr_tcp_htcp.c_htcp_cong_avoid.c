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
typedef  int /*<<< orphan*/  u32 ;
struct tcp_sock {int snd_cwnd_cnt; int snd_cwnd; int snd_cwnd_clamp; } ;
struct sock {int dummy; } ;
struct htcp {int alpha; int pkts_acked; } ;

/* Variables and functions */
 int /*<<< orphan*/  htcp_alpha_update (struct htcp*) ; 
 struct htcp* inet_csk_ca (struct sock*) ; 
 scalar_t__ tcp_in_slow_start (struct tcp_sock*) ; 
 int /*<<< orphan*/  tcp_is_cwnd_limited (struct sock*) ; 
 struct tcp_sock* tcp_sk (struct sock*) ; 
 int /*<<< orphan*/  tcp_slow_start (struct tcp_sock*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void htcp_cong_avoid(struct sock *sk, u32 ack, u32 acked)
{
	struct tcp_sock *tp = tcp_sk(sk);
	struct htcp *ca = inet_csk_ca(sk);

	if (!tcp_is_cwnd_limited(sk))
		return;

	if (tcp_in_slow_start(tp))
		tcp_slow_start(tp, acked);
	else {
		/* In dangerous area, increase slowly.
		 * In theory this is tp->snd_cwnd += alpha / tp->snd_cwnd
		 */
		if ((tp->snd_cwnd_cnt * ca->alpha)>>7 >= tp->snd_cwnd) {
			if (tp->snd_cwnd < tp->snd_cwnd_clamp)
				tp->snd_cwnd++;
			tp->snd_cwnd_cnt = 0;
			htcp_alpha_update(ca);
		} else
			tp->snd_cwnd_cnt += ca->pkts_acked;

		ca->pkts_acked = 1;
	}
}