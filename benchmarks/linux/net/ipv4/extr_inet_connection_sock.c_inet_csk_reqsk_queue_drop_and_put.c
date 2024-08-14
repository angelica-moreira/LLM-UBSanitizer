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
struct request_sock {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  inet_csk_reqsk_queue_drop (struct sock*,struct request_sock*) ; 
 int /*<<< orphan*/  reqsk_put (struct request_sock*) ; 

void inet_csk_reqsk_queue_drop_and_put(struct sock *sk, struct request_sock *req)
{
	inet_csk_reqsk_queue_drop(sk, req);
	reqsk_put(req);
}