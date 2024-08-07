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
struct sk_buff {int dummy; } ;
struct sctp_ulpq {int /*<<< orphan*/  reasm_uo; int /*<<< orphan*/  reasm; int /*<<< orphan*/  lobby; } ;
struct sctp_ulpevent {int dummy; } ;

/* Variables and functions */
 struct sk_buff* __skb_dequeue (int /*<<< orphan*/ *) ; 
 struct sctp_ulpevent* sctp_skb2event (struct sk_buff*) ; 
 int /*<<< orphan*/  sctp_ulpevent_free (struct sctp_ulpevent*) ; 

void sctp_ulpq_flush(struct sctp_ulpq *ulpq)
{
	struct sk_buff *skb;
	struct sctp_ulpevent *event;

	while ((skb = __skb_dequeue(&ulpq->lobby)) != NULL) {
		event = sctp_skb2event(skb);
		sctp_ulpevent_free(event);
	}

	while ((skb = __skb_dequeue(&ulpq->reasm)) != NULL) {
		event = sctp_skb2event(skb);
		sctp_ulpevent_free(event);
	}

	while ((skb = __skb_dequeue(&ulpq->reasm_uo)) != NULL) {
		event = sctp_skb2event(skb);
		sctp_ulpevent_free(event);
	}
}