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
struct westwood {int /*<<< orphan*/  rtt; } ;
struct sock {int dummy; } ;
struct ack_sample {scalar_t__ rtt_us; } ;

/* Variables and functions */
 struct westwood* inet_csk_ca (struct sock*) ; 
 int /*<<< orphan*/  usecs_to_jiffies (scalar_t__) ; 

__attribute__((used)) static void tcp_westwood_pkts_acked(struct sock *sk,
				    const struct ack_sample *sample)
{
	struct westwood *w = inet_csk_ca(sk);

	if (sample->rtt_us > 0)
		w->rtt = usecs_to_jiffies(sample->rtt_us);
}