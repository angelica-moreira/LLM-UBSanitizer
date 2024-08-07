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
struct sock {int dummy; } ;
struct ccid3_hc_tx_sock {int tx_x_recv; int tx_x; scalar_t__ tx_p; scalar_t__ tx_x_calc; int /*<<< orphan*/  tx_t_ld; scalar_t__ tx_rtt; scalar_t__ tx_s; } ;
typedef  scalar_t__ s64 ;
typedef  int /*<<< orphan*/  ktime_t ;
typedef  int __u64 ;

/* Variables and functions */
 int TFRC_T_MBI ; 
 int ccid3_hc_tx_idle_rtt (struct ccid3_hc_tx_sock*,int /*<<< orphan*/ ) ; 
 struct ccid3_hc_tx_sock* ccid3_hc_tx_sk (struct sock*) ; 
 int /*<<< orphan*/  ccid3_pr_debug (char*,unsigned int,unsigned int,scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  ccid3_update_send_interval (struct ccid3_hc_tx_sock*) ; 
 int /*<<< orphan*/  ktime_get_real () ; 
 scalar_t__ ktime_us_delta (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* max (int,int) ; 
 void* min (int,int) ; 
 int rfc3390_initial_rate (struct sock*) ; 
 int scaled_div (int,scalar_t__) ; 

__attribute__((used)) static void ccid3_hc_tx_update_x(struct sock *sk, ktime_t *stamp)
{
	struct ccid3_hc_tx_sock *hc = ccid3_hc_tx_sk(sk);
	__u64 min_rate = 2 * hc->tx_x_recv;
	const __u64 old_x = hc->tx_x;
	ktime_t now = stamp ? *stamp : ktime_get_real();

	/*
	 * Handle IDLE periods: do not reduce below RFC3390 initial sending rate
	 * when idling [RFC 4342, 5.1]. Definition of idling is from rfc3448bis:
	 * a sender is idle if it has not sent anything over a 2-RTT-period.
	 * For consistency with X and X_recv, min_rate is also scaled by 2^6.
	 */
	if (ccid3_hc_tx_idle_rtt(hc, now) >= 2) {
		min_rate = rfc3390_initial_rate(sk);
		min_rate = max(min_rate, 2 * hc->tx_x_recv);
	}

	if (hc->tx_p > 0) {

		hc->tx_x = min(((__u64)hc->tx_x_calc) << 6, min_rate);
		hc->tx_x = max(hc->tx_x, (((__u64)hc->tx_s) << 6) / TFRC_T_MBI);

	} else if (ktime_us_delta(now, hc->tx_t_ld) - (s64)hc->tx_rtt >= 0) {

		hc->tx_x = min(2 * hc->tx_x, min_rate);
		hc->tx_x = max(hc->tx_x,
			       scaled_div(((__u64)hc->tx_s) << 6, hc->tx_rtt));
		hc->tx_t_ld = now;
	}

	if (hc->tx_x != old_x) {
		ccid3_pr_debug("X_prev=%u, X_now=%u, X_calc=%u, "
			       "X_recv=%u\n", (unsigned int)(old_x >> 6),
			       (unsigned int)(hc->tx_x >> 6), hc->tx_x_calc,
			       (unsigned int)(hc->tx_x_recv >> 6));

		ccid3_update_send_interval(hc);
	}
}